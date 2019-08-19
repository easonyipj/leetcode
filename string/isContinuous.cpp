//
// Created by Eason on 2019/8/17.
// 扑克牌顺子 牛客

#include<cmath>
#include "limits.h"
#include<iostream>
#include "vector"
#include <algorithm>

using namespace std;

namespace str{
    class isContinuous{
    public:
        static bool IsContinuous( vector<int>& numbers ) {
            if(numbers.empty() || numbers.size() != 5) {
                return false;
            }

            sort(numbers.begin(), numbers.end());

            int numberOfZero = 0;
            for(int i : numbers) {
                if(i == 0) {
                    numberOfZero++;
                }
            }

            int numberOfGap = 0;
            int pre = 0;
            for(int i = 1; i < numbers.size(); i++, pre++) {
                if(numbers[pre] != 0 && numbers[i] != 0) {
                    // 有相同的牌
                    if(numbers[pre] == numbers[i]) {
                        return false;
                    }
                    numberOfGap += numbers[i] - numbers[pre] + 1;
                }

            }

            return numberOfZero >= numberOfGap;

        }
    };
}

