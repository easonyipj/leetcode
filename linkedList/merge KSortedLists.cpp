//
// Created by Eason on 2019/9/9.
//
/**
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <vector>
#include "algorithm"

using namespace std;

struct ListNode {
         int val;
         ListNode *next;
         explicit ListNode(int x){
             val = x;
             next = nullptr;
         }
};

namespace linkedList{
    class MergeKSortedLists{
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {

            if(lists.empty()) {
                return nullptr;
            }

            if(lists.size() == 1) {
                return lists[0];
            }

            int mid = lists.size() / 2;

            vector<ListNode*> lists1;
            for(int i = 0; i < mid; i++) {
                lists1.push_back(lists[i]);
            }

            vector<ListNode*> lists2;
            for(int i = mid; i < lists.size(); i++) {
                lists2.push_back(lists[i]);
            }

            ListNode* res1 = mergeKLists(lists1);
            ListNode* res2 = mergeKLists(lists2);

            return mergeTwoLists(res1, res2);
        }
        static bool cmp(const ListNode* a, const ListNode* b) {
            return a -> val < b -> val;
        }
        ListNode* listSort(vector<ListNode*>& lists) {

            vector<ListNode*> nodes;

            for(ListNode* list : lists) {
                while(list != nullptr) {
                    nodes.push_back(list);
                    list = list -> next;
                }
            }

            if(nodes.empty()){
                return nullptr;
            }

            sort(nodes.begin(), nodes.end(), cmp);

            for(int i = 0; i < nodes.size(); i++) {
                if(i == nodes.size() - 1) {
                    nodes[i] -> next = nullptr;
                }else{
                    nodes[i] -> next = nodes[i + 1];
                }
            }

            return nodes[0];
        }



        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode* p1 = l1;
            ListNode* p2 = l2;

            if(p1 == nullptr) {
                return p2;
            }

            if(p2 == nullptr) {
                return p1;
            }

            ListNode head(0);
            ListNode* p = &head;

            while(p1 && p2) {
                if(p1 -> val > p2 -> val) {
                    p -> next = p2;
                    p2 = p2 -> next;
                }else{
                    p -> next = p1;
                    p1 = p1 -> next;
                }
                p = p -> next;
            }

            if(p1) {
                p -> next = p1;
            }

            if(p2) {
                p -> next = p2;
            }

            return head.next;
        }
    };
}