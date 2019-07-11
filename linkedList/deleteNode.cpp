//
// Created by 易平建 on 2019-07-01.
//
#include "stdlib.h"
#include "listNode.cpp"

namespace linkedList{
    class deleteNode{
    public:
        static void deleteListNode(ListNode* node) {
            if(node == nullptr || node->next == nullptr) {
                return;
            }

            ListNode* p = node;
            p->val = node->next->val;
            p->next = node->next->next;

        }
    };
}

