//
// Created by Eason on 2019/8/17.
// 轰炸敌人 https://www.lintcode.com/problem/bomb-enemy/description

#include<cmath>
#include "limits.h"
#include<iostream>
#include "vector"
#include "algorithm"

using namespace std;

namespace dp{
    class bombEnemy {
    public:
        static int maxKilledEnemies(vector<vector<char>> &grid) {
            // write your code here

            if(grid.empty()) {
                return 0;
            }

            int m = grid.size();
            int n = grid[0].size();

            vector<vector<int>> dp(m, vector<int>(n));
            vector<vector<int>> killedNums(m, vector<int>(n));

            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    killedNums[i][j] = 0;
                }
            }

            // 1、计算从当前位置到最上方一共可以炸死多少个敌人
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(grid[i][j] == 'W') {
                        dp[i][j] = 0;
                    }
                    else{
                        dp[i][j] = 0;
                        if(grid[i][j] == 'E') {
                            dp[i][j] = 1;
                        }

                        if(i > 0) {
                            dp[i][j] += dp[i - 1][j];
                        }
                    }

                    killedNums[i][j] += dp[i][j];
                }
            }

            // 2、计算从当前位置到最下方一共可以炸死多少个敌人
            for(int i = m - 1; i >= 0; i--) {
                for(int j = 0; j < n; j++) {
                    if(grid[i][j] == 'W') {
                        dp[i][j] = 0;
                    }
                    else{
                        dp[i][j] = 0;
                        if(grid[i][j] == 'E') {
                            dp[i][j] = 1;
                        }

                        if(i < m - 1) {
                            dp[i][j] += dp[i + 1][j];
                        }
                    }

                    killedNums[i][j] += dp[i][j];
                }
            }

            // 3、计算从当前位置到最左方一共可以炸死多少个敌人
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(grid[i][j] == 'W') {
                        dp[i][j] = 0;
                    }
                    else{
                        dp[i][j] = 0;
                        if(grid[i][j] == 'E') {
                            dp[i][j] = 1;
                        }

                        if(j > 0) {
                            dp[i][j] += dp[i][j - 1];
                        }
                    }

                    killedNums[i][j] += dp[i][j];
                }
            }

            // 4、计算从当前位置到最右方一共可以炸死多少个敌人
            for(int i = 0; i < m; i++) {
                for(int j = n - 1; j >= 0; j--) {
                    if(grid[i][j] == 'W') {
                        dp[i][j] = 0;
                    }
                    else{
                        dp[i][j] = 0;
                        if(grid[i][j] == 'E') {
                            dp[i][j] = 1;
                        }

                        if(j < n - 1) {
                            dp[i][j] += dp[i][j + 1];
                        }
                    }

                    killedNums[i][j] += dp[i][j];
                }
            }

            // 5、计算最大值
            int maxKills = 0;
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(grid[i][j] == '0') {
                        maxKills = max(maxKills, killedNums[i][j]);
                    }
                }
            }

            return maxKills;
        }
    };
}

