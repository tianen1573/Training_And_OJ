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
    bool isPalindrome(ListNode* head) {

        int n = 0;
        ListNode * cur = head;
        while(cur)
        {
            ++ n;
            cur = cur->next;
        }
        cur = head;
        n /= 2;
        while(n > 1)
        {
            -- n;
            cur = cur->next;
        }
        ListNode *pre = cur;
        cur = cur->next;
        pre->next = nullptr;

        pre = nullptr;
        while(cur)
        {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        cur = head;
        while(cur && pre)
        {
            if(cur->val != pre->val)
                return false;
            cur = cur->next;
            pre = pre->next;
        }
        return true;
    }
};