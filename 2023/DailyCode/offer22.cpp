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
    ListNode* getKthFromEnd(ListNode* head, int k) {

        ListNode *fast = head, *last = head;

        while(k -- && fast)
        {
            fast = fast->next;
        }

        if(!k) return head;

        while(fast)
        {
            fast = fast->next;
            last = last->next;
        }

        return last;

    }
};