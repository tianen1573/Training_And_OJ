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

        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* cur = head;

        while(l1 || l2 || carry)
        {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;

            carry += (n1 + n2);
            auto *node = new ListNode(carry % 10);
            node->next = nullptr;
            cur->next = node;
            cur = node;
            carry /= 10;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        auto res = head->next;
        delete head;
        return res;

    }
};