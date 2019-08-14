//
// Created by Eason on 2019/8/8.
//
#include<iostream>
#include <vector>
#include "map"
#include "algorithm"

using namespace std;

namespace tree{
    class VerifySquenceOfBST{
    public:
        static bool verifySquenceOfBST(vector<int>& sequence) {
            if(sequence.empty()) {
                return false;
            }

            bool result =  recursive(sequence, 0, sequence.size() - 1);
            return result;
        }

        //BST的后序序列的合法序列是，对于一个序列S，最后一个元素是x （也就是根），如果去掉最后一个元素的序列为T，那么T满足：
        // T可以分成两段，前一段（左子树）小于x，后一段（右子树）大于x，且这两段（子树）都是合法的后序序列。
        static bool recursive(vector<int>& vec, int l, int r) {
            if(l >= r) {
                return true;
            }

            int i = r;
            while(i > l && vec[i - 1] > vec[r]) {
                i--;
            }

            for(int j = i - 1; j >= l; j--) {
                if(vec[j] > vec[r]) {
                    return false;
                }
            }

            return recursive(vec, l, i - 1) && recursive(vec, i, r - 1);
        }

    };
}
