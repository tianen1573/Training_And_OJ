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
    // 线性表：把节点保存下来，重新排序
    // 找中点，右半翻转，合并
    void reorderList(ListNode* head) {

        // vector<ListNode*> arr;
        // while(head)
        // {
        //     arr.push_back(head);
        //     head = head->next;
        // }
        // int l = 0, r = arr.size() - 1;
        // ListNode* Head = new ListNode();
        // ListNode* cur = Head;
        // while(l < r)
        // {
        //     cur->next = arr[l];
        //     arr[l]->next = arr[r];
        //     cur = arr[r];
        //     ++ l, -- r;
        // }
        // if(l == r)
        // {
        //     cur->next = arr[l];
        //     cur = arr[l];
        // }
        // cur->next = nullptr;
        // head = Head->next;
        // delete Head;

        // ----------------------

        // 找中点
        int n = 0;
        ListNode* cur = head;
        while(cur)
        {
            ++ n;
            cur = cur->next;
        }
        n /= 2;
        cur = head;
        while(n > 1)
        {
            -- n;
            cur = cur->next;
        }
        ListNode *pre = cur;
        cur = cur->next;
        pre->next = nullptr; //将左链表的尾节点处理为nullptr
        // 逆转
        // pre，cur，next 或者 哨兵头插法
        pre = nullptr; //将链表的尾节点处理为nullptr
        while(cur)
        {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        // 合并
        cur = head;
        while(cur && pre)
        {
            ListNode *cn = cur->next, *pn = pre->next;
            cur->next = pre;
            cur = cn;
            if(cur) pre->next = cur;
            pre = pn;
        }
    }
};