//
// Created by 易平建 on 2019-06-28.
// 硬币找零 https://leetcode-cn.com/problems/coin-change/
// 题解 https://leetcode-cn.com/problems/coin-change/solution/dong-tai-gui-hua-suan-fa-si-xiang-by-hikes/
#include<cmath>
#include "limits.h"
#include<iostream>
#include "vector"

using namespace std;

namespace dp{
    class coinsCash{
    public:
        // amount 要找零的金额
        // coins 零钱数组 {1, 3, 5}...
        static int coinsChange(vector<int>& coins, int amount){
            if(coins.empty()) {
                return -1;
            }

            vector<int> dp(amount + 1);
            dp[0] = 0;

            for(int i = 1; i <= amount; i++){
                int ans = INT_MAX;
                for(int coin : coins) {
                    int temp;
                    if(i < coin){
                        temp = INT_MAX;
                    }else{
                        temp = dp[i - coin] == INT_MAX ? INT_MAX : dp[i - coin] + 1;
                    }
                    ans = min(temp, ans);
                }
                dp[i] = ans;
            }

            return dp[amount] == INT_MAX ? -1 : dp[amount];

        }
    };
}

