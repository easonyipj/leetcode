//
// Created by Eason on 2019/7/13.
// 复制IP地址 https://leetcode-cn.com/problems/restore-ip-addresses/
// 参考答案 https://www.cnblogs.com/wmx24/p/10149489.html
#include "vector"
#include "string"
using namespace std;

namespace backtracking{
    class restoreIpAddresses{
    public:
        static vector<string> copyIpAddresses(string& s) {

        }

        static void findIp(string& s, int idx, int part, string temp, vector<string> &res) {
            if(part == 4 && idx == s.length()) {
                res.emplace_back(temp.substr(0, temp.length() - 1));
            }

            else if(part < 4) {
                if(s[idx] == '0') {
                    findIp(s, idx + 1, part + 1, temp + "0.", res);
                    return;
                }
                for(int i = 1; i < 4; i++) {
                    if(idx + i - 1 == s.length()) {
                        return;
                    }
                    int address = stoi(s.substr(idx, i));
                    if(address < 256) {
                        findIp(s, idx + i, part + 1, temp + to_string(address) + ".", res);
                    }
                }
            }

        }




    };
}



