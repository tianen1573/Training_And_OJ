/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // 是否有环：若快慢指针相遇，则一定有环，此时慢指针一定未走完一圈
    // 此时一个节点从头出发，一个节点从相遇处出发，两个节点相遇时，就是入口
    ListNode *detectCycle(ListNode *head) {
        
        if(head == nullptr || head->next == nullptr) return nullptr;

        ListNode *fast = head->next->next, *tail = head->next;
        while(fast != nullptr && fast != tail)
        {
            if(fast->next == nullptr) return nullptr;
            fast = fast->next->next;
            tail = tail->next;
        }
        if(fast == nullptr) return nullptr;

        tail = head;
        while(tail != fast)
        {
            tail = tail->next;
            fast = fast->next;
        }

        return fast;
    }
};