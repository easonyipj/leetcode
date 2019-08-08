//
// Created by Eason on 2019/8/6.
//

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(nullptr), right(nullptr) {
    }
}TreeNode;

