//
// Created by 易平建 on 2019-06-28.
// 硬币找零 https://blog.csdn.net/qq_37807889/article/details/84953159
#include<cmath>
#include "limits.h"
#include<iostream>

namespace dp{
    class coinsCash{
    public:
        // n 要找零的金额
        // coins 零钱数组 {1, 3, 5}...
        // coinNum 硬币种类数
        static int coinsChange(int n, int* coins, int coinNum){
            // 对应金额需要的硬币
            int cost[n + 1];
            cost[0] = 0;
            for(int i = 1; i < n + 1; i++) {
                // 初始化为最大值
                cost[i] = INT_MAX;
            }

            for(int i = 1; i <= n; i++) {
                for(int j = 0; j < coinNum; j++) {
                    if(coins[j] <= i){
                        cost[i] = std::fmin(cost[i], cost[i - coins[j]] + 1);
                    }
                }
            }

            return cost[n];
        }
    };
}

