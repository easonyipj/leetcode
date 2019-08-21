//
// Created by Eason on 2019/8/20.
// 简单密码
// https://www.nowcoder.com/practice/7960b5038a2142a18e27e4c733855dac?tpId=37&tqId=21244&tPage=2&rp=&ru=/ta/huawei&qru=/ta/huawei/question-ranking



#include<iostream>
#include "string"
#include "cstring"
#include "vector"

using namespace std;

namespace str{
    class simplepass{
    public:
        static void toSimplePass(vector<string> & ss) {

            // 大写字母转换
            vector<char> highLetter(26);
            for(int i = 0; i < 26; i++) {
                if(i == 25) {
                    highLetter[i] = 'a';
                }else{
                    highLetter[i] = char(97 + i + 1);
                }
            }

            // 小写字母转换
            vector<char> lowLetter(26);
            for(int i = 0; i < 26; i++) {
                // abc = 2
                if(i <= 14) {
                    lowLetter[i] = char(2 + i / 3 + 48);
                }

                if(i >= 15 && i <= 18) {
                    lowLetter[i] = '7';
                }

                if(i >= 19 && i <= 21) {
                    lowLetter[i] = '8';
                }

                if(i >= 22 && i <= 25){
                    lowLetter[i] = '9';
                }
            }

            for(string &s : ss) {

                for(int i = 0; i < s.size(); i++) {

                    if(s[i] >= 'A' && s[i] <= 'Z') {
                        s[i] = highLetter[s[i] - 'A'];
                        continue;
                    }

                    if(s[i] >= 'a' && s[i]  <= 'z') {
                        s[i] = lowLetter[s[i] - 'a'];
                        continue;
                    }

                }

                cout<<s<<endl;
            }
        }
    };
}

