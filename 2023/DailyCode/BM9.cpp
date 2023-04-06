class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* removeNthFromEnd(ListNode* pHead, int k) {
        // write code here
        ListNode *ret = new ListNode(-1);
        ret->next = pHead;

        ListNode *fast = pHead, *last = pHead;
        while(k-- && fast)
        {
            fast = fast->next;
        }
        if(k != -1) return nullptr;

        ListNode *prev = ret;
        while(fast)
        {
            prev = prev->next;
            fast = fast->next;
            last = last->next;
        }

        prev->next = last->next;
        delete last;
        ListNode *res = ret->next;
        delete ret;
        return res;
    }
};