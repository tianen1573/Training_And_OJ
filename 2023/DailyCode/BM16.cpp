/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
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
        if(!head || !head->next) return head;

        ListNode* Head = new ListNode(head->val + 1);
        Head->next = nullptr;
        ListNode* prev = Head, *cur = head;//prev合法链表的最后一个节点
        int val = prev->val;//前一个节点的值

        while (cur) 
        {
            if (cur->val != val) //不等于前一个节点
            {
                if(cur->next && cur->val != cur->next->val)//存在next，并且不相等
                {
                    prev->next = cur;
                    prev = cur;
                }
                else if(cur->next == nullptr)//不存在next
                {
                    prev->next = cur;
                    prev = cur;
                }
            }
            //val，cur 一直更新
            val = cur->val;
            cur = cur->next;
        }
        //结尾
        if(prev)
            prev->next = nullptr;

        return Head->next;
    }
};