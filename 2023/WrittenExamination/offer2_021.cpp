/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* newHead = new ListNode();
        newHead->next = head;
        ListNode *fast = newHead, *tail = newHead;

        for(int i = 0; i <= n; ++ i) // fast多走一步，使得tail编成倒数第n个的父节点
            fast = fast->next;
        while(fast)
        {
            fast = fast->next;
            tail = tail->next;
        }
        tail->next = tail->next->next;

        return newHead->next;
    }
};