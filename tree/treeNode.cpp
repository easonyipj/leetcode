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

// 建树代码
//TreeNode node1_1 = TreeNode(4);
//TreeNode node2_1 = TreeNode(5);
//TreeNode node2_2 = TreeNode(3);
//TreeNode node3_1 = TreeNode(6);
//TreeNode node3_2 = TreeNode(2);
//TreeNode node3_3 = TreeNode(5);
//
//node1_1.left = &node2_1;
//node1_1.right = &node2_2;
//node2_1.left = &node3_1;
//node2_1.right = &node3_2;
//node2_2.right = &node3_3;
