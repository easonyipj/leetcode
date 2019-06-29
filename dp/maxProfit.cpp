//
// Created by 易平建 on 2019-06-29.
// 买股票系列
#include "vector"


namespace dp{
    class maxProfit{
    public:
        // 1 https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
        static int getMaxProfit(std::vector<int>& prices) {

            if(prices.size() < 2) {
                return 0;
            }

            // min为历史最低价位
            // max为最大利润
            int min = prices[0];
            int max = 0;

            // 不断比较当前价位和历史最低价位 当前最大利润总是在（当前价位-历史最低价位）和 历史最大利润中产生
            // max = max(prices[i] - min, max)
            for(int i = 1; i < prices.size(); i++) {
                if(prices[i] > min) {
                    int sum = prices[i] - min;
                    if(sum > max) {
                        max = sum;
                    }
                }else {
                    min = prices[i];
                }
            }

            return max;
        }

        // 2 https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
        static int getMaxProfitII(std::vector<int>& prices) {

            if(prices.size() < 2) {
                return 0;
            }

            // min为历史最低价位
            // max为最大利润
            int min = prices[0];
            int max = 0;

            // 不断比较当前价位和历史最低价位 当前最大利润总是在（当前价位-历史最低价位）和 历史最大利润中产生
            // max = max(prices[i] - min, max)
            for(int i = 1; i < prices.size(); i++) {
                if(prices[i] > min) {
                    int sum = prices[i] - min;
                    if(sum > max) {
                        max = sum;
                    }
                }else {
                    min = prices[i];
                }
            }

            return max;
        }




    };
}

