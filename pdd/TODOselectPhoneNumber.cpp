//
// Created by Eason on 2019/9/3.
//
/**
 * A 国的手机号码由且仅由 N 位十进制数字(0-9)组成。一个手机号码中有至少 K 位数字相同则被定义为靓号。A 国的手机号可以有前导零，比如 000123456 是一个合法的手机号。
小多想花钱将自己的手机号码修改为一个靓号。修改号码中的一个数字需要花费的金额为新数字与旧数字之间的差值。比如将 1 修改为 6 或 6 修改为 1 都需要花 5 块钱。
给出小多现在的手机号码，问将其修改成一个靓号，最少需要多少钱？

输入描述:
第一行包含2个整数 N、K，分别表示手机号码数字个数以及靓号至少有 K 个数字相同。
第二行包含 N 个字符，每个字符都是一个数字('0'-'9')，数字之间没有任何其他空白符。表示小多的手机号码。
数据范围：
2 <= K <= N <= 10000

输出描述:
第一行包含一个整数，表示修改成一个靓号，最少需要的金额。
第二行包含 N 个数字字符，表示最少花费修改的新手机号。若有多个靓号花费都最少，则输出字典序最小的靓号。

输入例子1:
6 5
787585

输出例子1:
4
777577
 */
#include "iostream"
#include <queue>
#include <string>
#include <algorithm>
#include <sstream>


using namespace std;

class selectPhoneNumber{
public:
    static void main() {

        vector<int> number(10, 0);
        vector<int> times(10, 0);
        string ansstr;
        int ansi;
        int n, k;
        int anscost = -1;
        string str;
        bool flag = false;
        cin>>n>>k;
        char c;
        for(int i = 0; i < n; i++){
            cin>>c;
            str.push_back(c);
            number[c-'0']++;
            if(number[c-'0'] >= k){
                flag = true;
            }
        }
        if(flag) cout<<str<<endl;
        else{
            for(int i = 0; i <= 9; i++){
                for(int ii = 0; ii <= 9; ii++) times[ii] = 0;
                if(number[i] == 0) continue;
                int tmpcost = 0;
                int t = number[i];
                int dif = 1;
                while(t < k){
                    if(i+dif <= 9){
                        if(number[i+dif] + t >= k){
                            times[i+dif] = k-t;
                            tmpcost += (dif)*(k-t);
                            break;
                        }
                        else{
                            times[i+dif] = number[i+dif];
                            tmpcost += (dif)*number[i+dif];
                            t += number[i+dif];
                        }
                    }
                    if(i-dif >= 0){
                        if(number[i-dif] + t >= k){
                            times[i-dif] = k-t;
                            tmpcost += dif*(k-t);
                            break;
                        }
                        else{
                            times[i-dif] = number[i-dif];
                            tmpcost += number[i-dif];
                            t += number[i-dif];
                        }
                    }
                    dif++;
                }
                string sstr(str);
                for(int j = 0; j < sstr.size(); j++){
                    int ttt = sstr[j]-'0';
                    if(sstr[j]-'0' > i && times[(int)(sstr[j]-'0')] > 0){
                        times[ttt] = times[(int)(sstr[j]-'0')]- 1;
                        sstr[j] = '0'+i;
                    }
                }
                cout<<"  "<<endl;
                for(int j = sstr.size()-1; j >= 0; j--){
                    if(sstr[j]-'0' < i && times[(int)(sstr[j]-'0')] > 0){
                        times[(int)(sstr[j]-'0')]--;
                        sstr[j] = '0'+i;
                    }
                }
                if(anscost == -1){
                    anscost = tmpcost;
                    ansi = i;
                    ansstr = sstr;
                }
                else if(anscost > tmpcost){
                    ansi = i;
                    anscost = tmpcost;
                    ansstr = sstr;

                }
                else if(anscost == tmpcost){
                    anscost = tmpcost;
                    if(ansstr > sstr){
                        ansi = i;
                        ansstr = sstr;
                    }
                }
            }
            cout<<anscost<<endl;
            cout<<ansstr<<endl;
        }




    }
};