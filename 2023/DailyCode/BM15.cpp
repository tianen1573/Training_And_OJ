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
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here  
        if(!head) return nullptr;

        ListNode *cur = head;

        while(cur && cur->next)
        {
            if(cur->val != cur->next->val) cur = cur->next;
            else
            {
                cur->next = cur->next->next;
            };
        }

        return head;
    }
};