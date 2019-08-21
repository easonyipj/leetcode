//
// Created by Eason on 2019/8/20.
// 字符串最后一个单词长度 https://www.nowcoder.com/practice/8c949ea5f36f422594b306a2300315da?tpId=37&tqId=21224&tPage=1&rp=&ru=/ta/huawei&qru=/ta/huawei/question-ranking

#include<iostream>
#include "string"
#include "cstring"
#include "vector"

using namespace std;

namespace str{
    class lastLength{
    public:
        static int getLastLength(string s) {
            vector<string> ss;

            int i = 0;
            while(i < s.size() && s[i] != '\0') {
                string string1;
                while(i < s.size() && s[i] != ' ') {
                    string1 += s[i];
                    i++;
                }

                ss.push_back(string1);
                i++;
            }

            return ss[ss.size() - 1].size();
        }
    };
}