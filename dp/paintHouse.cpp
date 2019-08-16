//
// Created by Eason on 2019/8/16.
// 粉刷房子 https://www.lintcode.com/problem/paint-house/description

#include "vector"
#include "limits.h"

using namespace std;

namespace dp{
    class paintHouse{
    public:
        int minCost(vector<vector<int>> &costs) {
            int n = costs.size();
            if(costs.empty()) {
                return 0;
            }

            // dp[i][j]表示前i套（i从1开始，表示前1套房子，前i套房子的最后一套是第i - 1套）
            // 房子粉刷第j种颜色所需的最小花费
            // dp[i][j] = 前i - 1套房子装修除j外的两种颜色的最小花费　＋　第i - 1套房子装修j种颜色的花费
            // dp[i][0] = min(dp[i - 1][1] + costs[i - 1][0], dp[i - 1][2] + costs[i - 1][0])
            // dp[i][1] = min(dp[i - 1][0] + costs[i - 1][1], dp[i - 1][2] + costs[i - 1][1])
            // dp[i][2] = min(dp[i - 1][0] + costs[i - 1][2], dp[i - 1][1] + costs[i - 1][2])
            vector<vector<int>> dp(n + 1, vector<int>(3));

            dp[0][0] = dp[0][1] = dp[0][2] = 0;

            for(int i = 1; i <= n; i++) {
                for(int j = 0; j < 3; j++) {
                    dp[i][j] = INT_MAX;
                    for(int preJ = 0; preJ < 3; preJ++) {
                        // 第i - 1套房子不能喝第i - 2套房子撞色
                        if(j == preJ) {
                            continue;
                        }
                        dp[i][j] = min(dp[i][j], dp[i - 1][preJ] + costs[i - 1][j]);
                    }
                }
            }

            int res = dp[n][0];
            res = min(res, dp[n][1]);
            res = min(res, dp[n][2]);
            return res;
        }
    };
}