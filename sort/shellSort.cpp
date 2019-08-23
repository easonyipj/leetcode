//
// Created by Eason on 2019/8/22.
// https://zh.wikipedia.org/wiki/%E5%B8%8C%E5%B0%94%E6%8E%92%E5%BA%8F#.E6.AD.A5.E9.95.BF.E5.BA.8F.E5.88.97
#include <vector>

using namespace std;

namespace sort{
    class shellSort{
    public:
        // 步长递减的插入排序
        static vector<int> sort(vector<int>& nums) {
            int n = nums.size();

            for(int gap = n / 2; gap > 0; gap /= 2) {
                for(int i = gap; i < n; i++) {
                    for(int j = i; j - gap >= 0; j -= gap) {
                        if(nums[j] < nums[j - gap]) {
                            int temp = nums[j];
                            nums[j] = nums[j - gap];
                            nums[j - gap] = temp;
                        }
                    }
                }
            }

            return nums;
        }
    };
}
