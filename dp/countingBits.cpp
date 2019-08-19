//
// Created by Eason on 2019/8/17.
// countingBits https://leetcode-cn.com/problems/counting-bits/

#include<cmath>
#include "limits.h"
#include<iostream>
#include "vector"
#include <algorithm>

using namespace std;

namespace dp{
    class countingBits{
    public:
        vector<int> countBits(int num) {
            // dp[i]表示i转换成二进制后‘1’的个数
            // dp[i] = dp[i >> 1] + i % 2;
            vector<int> dp(num + 1);
            dp[0] = 0;

            for(int i = 1; i <= num; i++) {
                dp[i] = dp[i >> 1] + (i % 2);
            }

            return dp;
        }
    };
}

