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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *a = headA, *b = headB;
        bool fa = true, fb = true;

        while(a && b && a != b)
        {
            a = (a->next == nullptr ? (fa ? fa = false, a = headB : nullptr) : a->next);
            b = (b->next == nullptr ? (fb ? fb = false, b = headA : nullptr) : b->next);
        }
        
        return a;
    }
};