//
// Created by Eason on 2019/8/22.
//
#include <vector>

using namespace std;

namespace sort{
    class mergeSort{
    public:
        static vector<int> sort(vector<int>& nums) {
            sort(nums, 0, nums.size() - 1);
            return nums;
        }

        static void sort(vector<int>& nums, int l, int r) {
            if(l == r) {
                return;
            }
            int mid = (l + r) / 2;
            sort(nums, l, mid);
            sort(nums, mid + 1, r);
            merge(nums, l, r, mid);

        }

        static void merge(vector<int>& nums, int l, int r, int mid) {
            int temp[r - l + 1];
            // temp[i]
            int i = 0;
            int p1 = l;
            int p2 = mid + 1;

            while(p1 <= mid && p2 <= r) {
                temp[i++] = nums[p1] < nums[p2] ? nums[p1++] : nums[p2++];
            }

            while(p1 <= mid) {
                temp[i++] = nums[p1++];
            }

            while(p2 <= r) {
                temp[i++] = nums[p2++];
            }

            for(int j = 0; j < r - l + 1; j++) {
                nums[l + j] = temp[j];
            }
        }
    };
}

