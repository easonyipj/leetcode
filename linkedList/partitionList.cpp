//
// Created by Eason on 2019/9/6.
//
/**
 *Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include "stdlib.h"
#include "listNode.cpp"

namespace linkedList{
    class partitionList{
    public:
        static ListNode* partition(ListNode* head, int x) {
            ListNode lessHead;
            ListNode moreHead;

            ListNode* lessPtr = &lessHead;
            ListNode* morePtr = &moreHead;

            while(head != nullptr) {
                if(head -> val < x) {
                    lessPtr -> next = head;
                    lessPtr = head;
                }else{
                    morePtr -> next = head;
                    morePtr = head;
                }
                head = head -> next;
            }

            morePtr -> next = nullptr;
            lessPtr -> next = (&moreHead) -> next;

            return (&lessHead) -> next;
        }
    };
}