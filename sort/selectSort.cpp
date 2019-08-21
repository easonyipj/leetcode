//
// Created by Eason on 2019/8/22.
//
#include <vector>

using namespace std;

namespace sort{
    class selectSort{
    public:
        //不断选择最小或最大放在排序区的最左或最右
        static vector<int> sort(vector<int>& nums) {
            int n = nums.size();
            for(int i = n - 1; i > 0; i--) {
                int max = i;
                for(int j = i - 1; j >= 0; j--) {
                    if(nums[j] > nums[max]) {
                        max = j;
                    }
                }

                int temp = nums[max];
                nums[max] = nums[i];
                nums[i] = temp;
            }
            return nums;
        }

        static vector<int> sortI(vector<int>& nums) {
            int n = nums.size();
            for(int i = 0; i < n; i++) {
                int min = i;
                for(int j = i + 1; j < n; j++) {
                    if(nums[j] < nums[min]) {
                        min = j;
                    }
                }

                int temp = nums[min];
                nums[min] = nums[i];
                nums[i] = temp;
            }
            return nums;
        }

    };
}
