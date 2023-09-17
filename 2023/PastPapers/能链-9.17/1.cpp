/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:

    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        // 两个哨兵位

        auto upHead = new ListNode(-1);
        auto upTail = upHead;
        auto lowHead = new ListNode(-1);
        auto lowTail = lowHead;


        while(pHead)
        {
            auto next = pHead->next;
            
            if(pHead->val < x)
            {
                lowTail->next = pHead;
                lowTail = pHead;    
            }
            else 
            {
                upTail->next = pHead;
                upTail = pHead;
            }
            pHead = next;
        }
        upTail->next = lowTail->next = nullptr;
        lowTail->next = upHead->next;
        delete upHead;
        pHead = lowHead->next;
        delete lowHead;

        return pHead;
    }
};