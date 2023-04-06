class Solution {
  public:
    /**
     *
     * @param head1 ListNode类
     * @param head2 ListNode类
     * @return ListNode类
     */

    ListNode* ReverseList(ListNode* pHead) {

        if (nullptr == pHead)
            return nullptr;

        ListNode* prev = nullptr;
        ListNode* cur = pHead;
        ListNode* next = cur->next;

        while (cur) {
            next = cur->next;

            cur->next = prev;
            prev = cur;

            cur = next;

        }

        return prev;

    }

    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here

        head1 = ReverseList(head1);
        head2 = ReverseList(head2);

        ListNode* newHead = nullptr;

        int val = 0;

        while (head1 || head2) {
            int v1 = head1 ? head1->val : 0;
            int v2 = head2 ? head2->val : 0;

            val = val + v1 + v2;

            ListNode* vNode = new ListNode(val % 10);
            vNode->next = newHead;
            newHead = vNode;
            val /= 10;

            head1 = head1 ? head1->next : nullptr;
            head2 = head2 ? head2->next : nullptr;
        }

        if (val) {
            ListNode* vNode = new ListNode(val);
            vNode->next = newHead;
            newHead = vNode;
        }

        return newHead;

    }
    //辅助栈
};