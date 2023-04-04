/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 * };
 */

class Solution {
  public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // write code here
        ListNode* Head = nullptr;
        ListNode* begin = head;
        int pos = 1;

        ListNode* cur = head;

        while (pos < m) {
            Head = cur;
            cur = cur->next;
            begin = cur;

            ++ pos;
        }

        ListNode* prev = nullptr, *next = nullptr;

        while (pos <= n && cur) {
            next = cur->next;

            cur->next = prev;
            prev = cur;

            cur = next;

            ++ pos;
        }

        if (Head) {
            Head->next = prev;
        } else {
            head = prev;
        }
        begin->next = cur;
        return head;

        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // write code here
        if (k == 1) return head;

        ListNode* cur = head;
        int pos = 1;
        while (cur) {
            
           
            int i = 0;
            for (; i < k && cur; ++ i) {
                cur = cur->next;
            }
 
            if(i == k)
            {
                head = reverseBetween(head, pos, pos + k - 1);
                pos += k;
            }

        }

        return head;
    }
};

//递归
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        //找到每次翻转的尾部
        ListNode* tail = head; 
        //遍历k次到尾部
        for(int i = 0; i < k; i++){ 
            //如果不足k到了链表尾，直接返回，不翻转
            if(tail == NULL) 
                return head;
            tail = tail->next; 
        }
        //翻转时需要的前序和当前节点
        ListNode* pre = NULL; 
        ListNode* cur = head;
        //在到达当前段尾节点前
        while(cur != tail){ 
            //翻转
            ListNode* temp = cur->next; 
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        //当前尾指向下一段要翻转的链表
        head->next = reverseKGroup(tail, k); 
        return pre;
    }
};
