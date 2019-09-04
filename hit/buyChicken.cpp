//
// Created by Eason on 2019/9/2.
//
/**
 * 题目描述
    用小于等于n元去买100只鸡，大鸡5元/只，小鸡3元/只,还有1/3元每只的一种小鸡，分别记为x只,y只,z只。编程求解x,y,z所有可能解。
输入描述:
    测试数据有多组，输入n。
输出描述:
    对于每组输入,请输出x,y,z所有可行解，按照x，y，z依次增大的顺序输出。
示例1
输入
40
输出
x=0,y=0,z=100
x=0,y=1,z=99
x=0,y=2,z=98
x=1,y=0,z=99
 */
#include "iostream"

using namespace std;

class buyChicken{
public:
    static void main() {
        int big;
        int small;
        int smaller;

        int n;

        while(cin >> n) {
            for(big = 0; big <= 100; big++){
                for(small = 0; small <= 100; small++) {
                    smaller = 100 - big - small;
                    if(big + small + smaller == 100 && 15 * big + 9 * small + 1 * smaller <= 3 * n) {
                        cout << "x=" << big << ",y=" << small << ",z=" << smaller << endl;
                    }
                }
            }
        }
    }
};
