//
// Created by Eason on 2019/8/16.
// 解码方法 https://leetcode-cn.com/problems/decode-ways/
#include<cmath>
#include "limits.h"
#include<iostream>
#include "vector"

using namespace std;

namespace dp{
    class decodeWays{
    public:
        static int numDecodings(string& s) {
            if(s.empty()) {
                return  0;
            }

            // dp[i]表示前i个字符s[0, i - 1]能解密的最大个数
            // dp[i] = dp[i - 1](s[i - 1]属于[1, 9]) + dp[i - 2](s[i - 2, i - 1]属于[10 ,26])

            vector<int> dp(s.size() + 1);

            // 前0个数字有0种解码方式
            dp[0] = 1;
            for(int i = 1; i <= s.size(); i++) {
                dp[i] = 0;
                int k = s[i - 1] - '0';
                if(k >= 1 && k <= 9) {
                    dp[i] += dp[i - 1];
                }

                if(i >= 2) {
                    k = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
                    if(k >= 10 && k <= 26) {
                        dp[i] += dp[i - 2];
                    }
                }
            }

            return dp[s.size()];
        }

    };
}


