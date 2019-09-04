//
// Created by Eason on 2019/9/4.
//
#include "./listNode.cpp"

using namespace std;

namespace linkedList{
    class IntersectionofTwoLinkedLists{
    public:
        static ListNode * getIntersection(ListNode *headA, ListNode *headB) {
            int lengthA = 0;
            int lengthB = 0;

            ListNode* countA = headA;
            ListNode* countB = headB;

            while(countA) {
                lengthA++;
                countA = countA -> next;
            }

            while(countB) {
                lengthB++;
                countB = countB -> next;
            }

            if(lengthA > lengthB) {
                int count = lengthA - lengthB;
                while(count && headA) {
                    headA = headA -> next;
                    count--;
                }
            }

            if(lengthB > lengthA) {
                int count = lengthB - lengthA;
                while(count && headB) {
                    headB = headB -> next;
                    count--;
                }
            }

            while(headA && headB) {
                if(headA == headB) {
                    return headA;
                }

                headA = headA -> next;
                headB = headB -> next;
            }

            return nullptr;

        }
    };
}

