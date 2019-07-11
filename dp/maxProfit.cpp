//
// Created by 易平建 on 2019-06-29.
// 买股票系列
#include "vector"
#include "limits.h"
#include<cmath>

namespace dp{
    class maxProfit{
    public:
        // 1 https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
        static int getMaxProfit(std::vector<int>& prices) {

            if(prices.size() < 2) {
                return 0;
            }

//            // 方法一
//            // min为历史最低价位
//            // max为最大利润
//            int min = prices[0];
//            int max = 0;
//
//            // 不断比较当前价位和历史最低价位 当前最大利润总是在（当前价位-历史最低价位）和 历史最大利润中产生
//            // max = max(prices[i] - min, max)
//            for(int i = 1; i < prices.size(); i++) {
//                if(prices[i] > min) {
//                    int sum = prices[i] - min;
//                    if(sum > max) {
//                        max = sum;
//                    }
//                }else {
//                    min = prices[i];
//                }
//            }
//
//            return max;

            // 方法二
            // dp_i_0 表示不持有股票时当前利润
            // dp_i_1 表示持有股票时当前利润

            int dp_i_0 = 0;
            int dp_i_1 = INT_MIN;

            for(int i = 0; i < prices.size(); i++) {
                dp_i_0 = std::max(dp_i_0, dp_i_1 + prices[i]);
                dp_i_1 = std::max(dp_i_1, -prices[i]);
            }

            return dp_i_0;

        }

        // 2 https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/

        static int getMaxProfitII(std::vector<int>& prices) {


            if(prices.size() < 2) {
                return 0;
            }
//            // 方法一
//
//            int sum = 0;
//
//            for(int i = 0; i < prices.size() - 1; i++) {
//                if(prices[i + 1] > prices[i]) {
//                    sum += prices[i + 1] - prices[i];
//                }
//            }
//
//            return sum;

            // 方法二
            int n = prices.size();
            int dp_0 = 0;
            int dp_1 = INT_MIN;
            for(int i = 0; i < n; i++) {
                int temp = dp_0;
                dp_0 = std::max(dp_0, dp_1 + prices[i]);
                dp_1 = std::max(dp_1, temp - prices[i]);
            }

            return dp_0;

        }

        // 3 https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/
        // 最多不同时完成两笔交易
        static int getMaxProfitIII(std::vector<int>& prices) {
            if(prices.size() < 2) {
                return 0;
            }
            int n = prices.size();
            int kmax = 2;
            std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(kmax + 1, std::vector<int>(2)));
            for(int i = 0; i < n; i++) {
                for(int k = 2; k >= 1; k--) {
                    if(i == 0) {
                        dp[i][k][0] = 0;
                        dp[i][k][1] = -prices[i];
                        continue;
                    }
                    dp[i][k][0] = std::max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
                    dp[i][k][1] = std::max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
                }
            }
            return dp[n - 1][kmax][0];

        }

        // 4 https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
        // 最多完成K笔交易
        static int getMaxProfitIV(int k, std::vector<int>& prices) {
            if(prices.size() < 2) {
                return 0;
            }

            int n = prices.size();
            int kmax = k;

            if(kmax > n / 2) {
                return getMaxProfitII(prices);
            }
            std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(kmax + 1, std::vector<int>(2)));
            for(int i = 0; i < n; i++) {
                for(int kindex = 2; kindex >= 1; kindex--) {
                    if(i == 0) {
                        dp[i][kindex][0] = 0;
                        dp[i][kindex][1] = -prices[i];
                        continue;
                    }
                    dp[i][kindex][0] = std::max(dp[i - 1][kindex][0], dp[i - 1][kindex][1] + prices[i]);
                    if(kindex == 1) {
                        dp[i][kindex][1] = std::max(dp[i - 1][kindex][1],  -prices[i]);
                        continue;
                    }
                    dp[i][kindex][1] = std::max(dp[i - 1][kindex][1], dp[i - 1][kindex - 1][0] - prices[i]);
                }
            }
            return dp[n - 1][kmax][0];

        }



    };
}

