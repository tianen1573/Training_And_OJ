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

    // 翻转链表
    // 辅助栈/数组/string
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        stack<int> s1, s2;

        while(l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode *head = new ListNode();
        int car = 0;
        while(s1.size() && s2.size())
        {
            int a = s1.top(); s1.pop();
            int b = s2.top(); s2.pop();

            car += a + b;
            ListNode *node = new ListNode(car % 10);
            car /= 10;
            node->next = head->next;
            head->next = node;
        }
        while(s1.size())
        {
            int a = s1.top(); s1.pop();
            car += a ;
            ListNode *node = new ListNode(car % 10);
            car /= 10;
            node->next = head->next;
            head->next = node;
        }
        while(s2.size())
        {
            int b = s2.top(); s2.pop();
            car += b ;
            ListNode *node = new ListNode(car % 10);
            car /= 10;
            node->next = head->next;
            head->next = node;
        }
        while(car)
        {
            ListNode *node = new ListNode(car % 10);
            car /= 10;
            node->next = head->next;
            head->next = node;
        }

        ListNode *ret = head->next;
        delete head;
        return ret;
    }
};