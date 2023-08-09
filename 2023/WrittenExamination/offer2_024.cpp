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
    ListNode* reverseList(ListNode* head) {

        ListNode *newHead = new ListNode();
        ListNode *cur = head;

        while(cur)
        {
            ListNode *next = cur->next;
            cur->next = newHead->next;
            newHead->next = cur;
            cur = next;
        }

        ListNode *ret = newHead->next;
        delete newHead;
        return ret;
    }
};