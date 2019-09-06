//
// Created by Eason on 2019/9/6.
//
/**
 * A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/copy-list-with-random-pointer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include "map"

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class copyList {
public:
    static Node* copyRandomList(Node* head) {

    }
};