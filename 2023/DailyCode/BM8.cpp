class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        
        ListNode *fast = pHead, *last = pHead;

        while(k-- && fast)
        {
            fast = fast->next;
        }
        if(k != -1) return nullptr;

        while(fast)
        {
            fast = fast->next;
            last = last->next;
        }

        return last;

    }
};