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

        // ListNode *h1 = headA, *h2 = headB;

        // int len1 = 0, len2 = 0;
        // while(h1)
        // {
        //     ++ len1;
        //     h1 = h1->next;
        // }
        // while(h2)
        // {
        //     ++ len2;
        //     h2 = h2->next;
        // }

        // h1 = headA, h2 = headB;
        // if(len1 > len2)
        // {
        //     while(len1 -- != len2)
        //     {
        //         h1 = h1->next;
        //     }
        // }
        // else if(len1 < len2)
        // {
        //     while(len2 -- != len1)
        //     {
        //         h2 = h2->next;
        //     }
        // }

        // while(h1 != h2)
        // {
        //     h1 = h1->next;
        //     h2 = h2->next;
        // }

        // return h1;


        ListNode *h1 = headA, *h2 = headB;
        bool f1 = true, f2 = true;
        while(h1 != h2 && h1 && h2)
        {
            h1 = h1->next;
            h2 = h2->next;

            if(f1 && !h1) f1 = false, h1 = headB;
            if(f2 && !h2) f2 = false, h2 = headA;
        }

        return h1 == h2 ? h1 : nullptr;
        
    }
};