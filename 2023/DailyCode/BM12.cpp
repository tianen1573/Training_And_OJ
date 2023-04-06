class Solution {
  public:
    /**
     *
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode* mergeSort(ListNode* left, ListNode* right) {
        if (!left) return right;
        if (!right) return left;

        ListNode* head = new ListNode(0);
        ListNode* cur = head;

        while (left && right) {
            if (left->val > right->val) {
                cur->next = right;
                right = right->next;
            } else {
                cur->next = left;
                left = left->next;
            }
            cur = cur->next;
        }

        cur->next = left ? left : right;
        ListNode * ret = head->next;
        delete head;
        return ret;
    }
    ListNode* sortInList(ListNode* head) {
        // write code here

        if(!head || !head->next)    return head;

        ListNode *left = head;
        ListNode *mid = head->next;
        ListNode *right = head->next->next;

        //先分
        while(right && right->next)
        {
            left = left->next;
            mid = mid->next;
            right = right->next->next;
        }
        left->next = nullptr;//把左边的链表独立

        //继续分 ，再治
        //分到单节点链表后，归并
        return mergeSort(sortInList(head), sortInList(mid));
        //链表排序首选归并排序，归并排序是自下而上的排序，变量之间不需要强相关
        //即边界的表示，可以是数组下标，可以是指针，对链表比较友好
    }
    //辅助数组
};