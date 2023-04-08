/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode* head) {
        // write code here
        if(!head || !head->next) return true;

        //求链表长度
        ListNode *cur = head;
        int len = 0;
        while(cur)
        {
            len ++ ;
            cur = cur->next;
        }

        //逆转前半部分链表
        cur = head;
        ListNode *prev = nullptr, *next;
        int mid = len / 2;
        for(int i = 0; i < mid; ++ i)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        if(len % 2) cur = cur->next;
        while(cur)
        {
            if(cur->val != prev->val) return false;
            cur = cur->next;
            prev = prev->next;
        }

        return true;
   

    }
};
//辅助栈/数组 -- 不改变原数组