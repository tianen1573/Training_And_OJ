/**
 * struct ListNode {
 *  int val;
 *  struct ListNode *next;
 *  ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode* oddEvenList(ListNode* head) {

        ListNode* Odd = new ListNode(-1);
        ListNode* Even = new ListNode(-1);
        Odd->next = nullptr, Even->next = nullptr;

        ListNode* odd = Odd, *even = Even;
        ListNode* cur = head;
        int flag = 1;
        while (cur) {
            if (flag == 1) {
                odd->next = cur;
                odd = cur;
            } else {
                even->next = cur;
                even = cur;
            }

            cur = cur->next;
            flag *= -1;
        }

        ListNode* ret;
        ret = Odd->next;
        if (odd->next == nullptr) {//奇数个需要处理nullptr
            even->next = nullptr;
        }
        odd->next = Even->next;

        delete Odd;
        delete Even;

        return ret;

    }
};