//
// Created by Eason on 2019/8/22.
//
#include <vector>

using namespace std;

namespace sort{
    class quickSort{
    public:
        static vector<int> sort(vector<int>& nums) {
            int n = nums.size();
            quicksort(nums, 0, n - 1);
            return nums;
        }

        static void quicksort(vector<int>& nums, int l, int r) {
            if(l < r) {
                int point = partition(nums, l, r);
                quicksort(nums, l, point - 1);
                quicksort(nums, point + 1, r);
            }
        }

        static int partition(vector<int>& nums, int l, int r) {
            int key = nums[l];
            while(l < r) {
                while(l < r && nums[r] >= key) {
                    r--;
                }
                swap(nums, r, l);

                while(l < r && nums[l] <= key) {
                    l++;
                }
                swap(nums, r, l);
            }
            nums[l] = key;
            return l;
        }

        static void swap(vector<int>& nums, int l, int r) {
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
        }

    };
}
