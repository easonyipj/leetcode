//
// Created by Eason on 2019/8/16.
// 粉刷房子 https://www.lintcode.com/problem/paint-house/description
// 粉刷房子 II https://www.lintcode.com/problem/paint-house-ii/

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

        int minCostII(vector<vector<int>> &costs) {
            if(costs.empty()) {
                return 0;
            }
            // m the number 0f house
            // n the number of color
            int m = costs.size();
            int n = costs[0].size();


            // dp[i][j]表示前i套（i从1开始，表示前1套房子，前i套房子的最后一套是第i - 1套）房子粉刷第j种颜色所需的最小花费

            vector<vector<int>> dp(m + 1, vector<int>(n));

            // 前0套房子装修所有颜色花费都是0
            for(int i = 0; i < n; i++) {
                dp[0][i] = 0;
            }

            // dp[i][j] = 前i - 1套房子装修除j外的颜色的最小花费　＋　第i - 1套房子装修j种颜色的花费
            for(int i = 1; i <= m; i++) {
                int min = INT_MAX;
                int minor = INT_MAX;
                int minIndex = -1;
                int minorIndex = -1;

                for(int k = 0; k < n; k++) {
                    if(dp[i - 1][k] < min) {
                        minor = min;
                        minorIndex = minIndex;
                        min = dp[i - 1][k];
                        minIndex = k;
                    }else if(dp[i - 1][k] < minor){
                        minor = dp[i - 1][k];
                        minorIndex = k;
                    }
                }

                for(int j = 0; j < n; j++) {
                    if(j == minIndex) {
                        dp[i][j] = minor + costs[i - 1][j];
                    }else{
                        dp[i][j] = min + costs[i - 1][j];
                    }
                }
            }

            int res = INT_MAX;
            for(int j = 0; j < n; j++) {
                res = min(res, dp[m][j]);
            }
            return res;
        }
    };
}