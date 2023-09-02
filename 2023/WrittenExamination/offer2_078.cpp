/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {


        auto cmp = [](ListNode* a, ListNode* b){return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> prique; // 传入类型
        for(auto ptr : lists)
        {
            if(!ptr) continue;
            prique.push(ptr);
        }

        ListNode *tmpHead = new ListNode();
        ListNode *curr = tmpHead;
        while(prique.size())
        {
            auto node = prique.top();
            prique.pop();
            auto next = node->next;

            node->next = nullptr;
            curr->next = node;
            curr = node;

            if(next)
                prique.push(next);
        }

        curr = tmpHead->next;
        delete tmpHead;
        return curr; 

    }
};