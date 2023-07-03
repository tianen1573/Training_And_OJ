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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        ListNode* head = nullptr;

        while(l1)
            s1.push(l1->val), l1 = l1->next;
        while(l2)
            s2.push(l2->val), l2 = l2->next;
        
        int carry = 0;
        while(s1.size() || s2.size() || carry)
        {
            int n1 = 0, n2 = 0;
            if(s1.size()) { n1 = s1.top(); s1.pop();}
            if(s2.size()) { n2 = s2.top(); s2.pop();}

            carry += (n1 + n2);

            ListNode* node = new ListNode(carry % 10);
            carry /= 10;

            node->next = head;
            head = node;
        }

        return head;
    }
};