//
// Created by Eason on 2019/8/16.
// 最小路径和 https://leetcode-cn.com/problems/minimum-path-sum/

#include<cmath>
#include "limits.h"
#include<iostream>
#include "vector"
#include "algorithm"

using namespace std;

namespace dp{
    class minimumPathSum{
    public:
        static int minPathSum(vector<vector<int>>& grid) {
            if(grid.empty()) {
                return 0;
            }

            int m = grid.size();
            int n = grid[0].size();

            vector<vector<int>> dp(m, vector<int>(n));

            dp[0][0] = grid[0][0];

            for(int i = 1; i < m; i++) {
                dp[i][0] = dp[i - 1][0] + grid[i][0];
            }

            for(int j = 1; j < n; j++) {
                dp[0][j] = dp[0][j - 1] + grid[0][j];
            }

            for(int i = 1; i < m; i++) {
                for(int j = 1; j < n; j++) {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }

            return dp[m - 1][n - 1];
        }

        // 利用滚动数组，计算第i行只需要第i行和第i - 1行的结果
        static int minPathSumOptSpace(vector<vector<int>>& grid) {
            if(grid.empty()) {
                return 0;
            }

            int m = grid.size();
            int n = grid[0].size();

            vector<vector<int>> dp(2, vector<int>(n));

            int pre = 0;
            int current = 1;

            for(int i = 0; i < m; i++) {
                pre = current;
                current = 1 - current;
                for(int j = 0; j < n; j++) {
                    if(i == 0 && j == 0) {
                        dp[current][j] = grid[i][j];
                        continue;
                    }

                    dp[current][j] = min(i > 0 ? dp[pre][j] : INT_MAX,
                            j > 0 ? dp[current][j - 1] : INT_MAX) + grid[i][j];

                }
            }

            return dp[current][n - 1];
        }
    };
}
