//
// Created by Eason on 2019/8/13.
// https://blog.csdn.net/legend_hua/article/details/81255270
// 子列表的和是否等于某一个数


#include "vector"

using namespace std;

namespace dp{
    class subset{
    public:
        bool dpsubset(vector<int>& arr, int s) {
            // set[i][s] 表示arr[0, i]中是否有子序列的和为s
            // i 表示arr下标
            vector<vector<int>> set(arr.size(), vector<int>(s + 1));

            // set[i][0] = 0
            for(int i = 0; i < arr.size(); i++) {
                set[i][0] = 0;
            }

            // 第一行（arr[0]）除了[0, s]中等于arr[0]处为1，其余为0
            for(int i = 0; i <= s; i++) {
                if(arr[0] == i) {
                    set[0][i] = 1;
                }
                set[0][i] = 0;
            }

            for(int i = 1; i < arr.size(); i++) {
                for(int j = 1; j <= s; j++) {
                    if(arr[i] > s) {
                        set[i][j] = set[i - 1][j];
                    }else{
                        bool A = set[i - 1][j - arr[i]];
                        bool B = set[i - 1][j];
                        set[i][j] = A || B;
                    }
                }
            }

            return set[arr.size() - 1][s];

        }
    };
}
