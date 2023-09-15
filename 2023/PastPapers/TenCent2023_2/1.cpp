// 牛妹有一堆数链，这些数链里面的数字都杂乱无章，牛
// 妹想整理—下这些数字，把它们从小到大排成—个数链

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

class cmp
{
public:
    bool operator()(ListNode* a, ListNode* b)
    {
        return a->val > b->val;
    }
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回一个指向链表头部的指针。
     * @param a ListNode类vector 指向这些数链的开头
     * @return ListNode类
     */
    
    ListNode* solve(vector<ListNode*>& arr) {
        
        priority_queue<ListNode*, vector<ListNode*>, cmp> pque;
        for(auto* node : arr)
            while(node)
            {
                pque.push(node);
                node = node->next;
            }
        if(pque.size() == 0)
            return nullptr;
        
        ListNode* Head = pque.top();
        pque.pop();
        ListNode* tail = Head;
        tail->next = nullptr;
        
        while(pque.size())
        {
            auto node = pque.top();
            pque.pop();
            
            node->next = nullptr;
            tail->next = node;
            tail = node;
        }
        
        return Head;
    }
};