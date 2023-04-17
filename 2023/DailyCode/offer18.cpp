/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {

        ListNode *Head = new ListNode();
        Head->next = head;
        ListNode *prev = Head;

        ListNode *cur = head;

        while(cur && cur->val != val)
        {
            prev = cur;
            cur = cur->next;
        }

        if(cur) prev->next = cur->next;

        return Head->next;
    }
};