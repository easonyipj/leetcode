//
// Created by Eason on 2019/8/21.
//
#include <vector>

using namespace std;

namespace sort{
    class insertSort{
    public:
        // 不断把排序区最小元素移到对应位置
        static vector<int> sort(vector<int>& nums) {
            int n = nums.size();
            for(int i = 1; i < n; i++) {
                for(int j = i; j > 0; j--) {
                    if(nums[j] < nums[j - 1]) {
                        int temp = nums[j - 1];
                        nums[j - 1] = nums[j];
                        nums[j] = temp;
                    }
                }
            }
            return nums;
        }
    };
}

