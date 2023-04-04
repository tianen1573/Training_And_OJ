
class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // write code here
        if(m == n)
            return head;

        ListNode *Head = nullptr;
        ListNode *begin = head;
        int pos = 1;

        ListNode *cur = head; 

        while(pos < m)
        {
            Head = cur;
            cur = cur->next;
            begin = cur;

            ++ pos;
        }

        ListNode *prev = nullptr, *next = nullptr;

        while(pos <= n)
        {
            next = cur->next;

			cur->next = prev;
			prev = cur;

			cur = next;
            
            ++ pos;
        }

        if(Head)
        {
            Head->next = prev;
        }
        else 
        {
            head = prev;
        }
        begin->next = cur;
        return head;

        return head;
    }
};