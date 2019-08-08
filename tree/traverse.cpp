//
// Created by Eason on 2019/8/6.
//
#include<iostream>
#include <vector>
#include "queue"
#include "map"
#include "algorithm"
#include "./treeNode.cpp"

using namespace std;

namespace tree{
    class traverse{
    public:
        static int depth(TreeNode* node) {
            if(node == nullptr) {
                return 0;
            }

            int l = depth(node->left);
            int r = depth(node->right);

            return l > r ? l + 1 : r + 1;

        }

        //  层序遍历-递归
        static int levelTraverse(TreeNode* node) {
            if(node == nullptr) {
                return 0;
            }

            int treeDepth = depth(node);

            for(int i = 1; i <= treeDepth; i++) {
                levelOrder(node, i);
            }
        }

        static void levelOrder(TreeNode* node, int length) {
            if(node == nullptr || length < 1) {
                return;
            }

            if(length == 1) {
                cout<<node->val<<endl;
            }

            levelOrder(node->left, length - 1);
            levelOrder(node->right, length - 1);
        }

        //  层序遍历-非递归
        //  1、将根节点保存到队列
        //  2、将节点出队，访问该节点，并依次将该节点的左、右节点入队
        //  3、重复2，直到队列为空
        static void levelTraverseWithQueue(TreeNode* node) {
            queue<TreeNode*> q;
            if(node == nullptr) {
                return;
            }

            q.push(node);
            while(!q.empty()) {
                TreeNode* currentNode = q.front();
                q.pop();
                cout<<currentNode->val<<endl;

                q.push(currentNode->left);
                q.push(currentNode->right);
            }

        }

    };
}
