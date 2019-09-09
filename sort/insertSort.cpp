//
// Created by Eason on 2019/8/21.
//
#include <vector>

using namespace std;

namespace sort{
    class insertSort{
    public:

        // 正统插入排序
        static vector<int> sort(vector<int>& nums) {
            int n = nums.size();
            for(int i = 1; i < n; i++) {
                int inserted = nums[i];
                int j = i - 1;
                for(; nums[j] > inserted && j >= 0; j--) {
                    nums[j + 1] = nums[j];
                }
                nums[j + 1] = inserted;
            }
            return nums;
        }
    };
}


