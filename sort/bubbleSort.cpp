//
// Created by Eason on 2019/8/21.
//
#include <vector>

using namespace std;

namespace sort{
    class bubbleSort{
    public:
        static vector<int> sort(vector<int>& nums) {
            int n = nums.size();
            for(int i = n - 1; i >= 1; i--) {
                for(int j = 0; j < i; j++) {
                    if(nums[j] > nums[j + 1]) {
                        int temp = nums[j];
                        nums[j] = nums[j + 1];
                        nums[j + 1] = temp;
                    }
                }
            }
            return nums;
        }

        // 改进I 内循环后没有进行交换 则排序完毕
        static vector<int> sortI(vector<int>& nums) {
            int n = nums.size();
            for(int i = n - 1; i >= 1; i--) {
                int flag = 0;
                for(int j = 0; j < i; j++) {
                    if(nums[j] > nums[j + 1]) {
                        int temp = nums[j];
                        nums[j] = nums[j + 1];
                        nums[j + 1] = temp;
                        flag = 1;
                    }
                }
                if(flag == 0) {
                    break;
                }
            }
            return nums;
        }
    };
}

