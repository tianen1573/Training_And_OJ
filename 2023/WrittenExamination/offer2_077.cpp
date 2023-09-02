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
    ListNode* sortList(ListNode* head) {

        if(head == nullptr)
            return nullptr;
        
        int len = 0;
        ListNode *nodeLen = head;
        while(nodeLen)
        {
            ++ len;
            nodeLen = nodeLen->next;
        }

        ListNode *tmpHead = new ListNode(0, head);
        // 区间长度由小到大
        for(int mergeLen = 1; mergeLen < len; mergeLen <<= 1)
        {
            // 每次都 重置prev，curr
            ListNode *prev = tmpHead, *curr = tmpHead->next;
            
            // 切割区间
            // 区间不一定 全满足mergeLen大小
            while(curr)
            {
                // 第一个区间的头节点
                ListNode *head1 = curr;
                // 若长度不够，求第一个区间的最后一个节点
                for(int i = 1; i < mergeLen && curr->next; ++ i)
                    curr = curr->next;
                // 第二个区间的头节点
                ListNode *head2 = curr->next;
                curr->next = nullptr; // 处理第一个区间的尾节点
                
                // 求下一个区间
                curr = head2;
                // curr可能不存在，若长度不够，求第一个区间的最后一个节点
                for(int i = 1; i < mergeLen && curr && curr->next; ++ i)
                    curr = curr->next;
                // 第二个区间的末尾节点
                ListNode *next = nullptr;
                if(curr)
                {
                    next = curr->next; // 下个区间的开头
                    curr->next = nullptr; // 处理第二个区间的尾节点
                }

                ListNode *mergeNode = merge(head1, head2); // 归并区间 
                prev->next = mergeNode; // 合并的两个区间 连接到上个区间
                // 更新prev
                while(prev->next)
                    prev = prev->next; // 求合并区间的末尾节点
                
                curr = next;
            }
        }
        head = tmpHead->next;
        delete tmpHead;
        return head;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) 
    {

        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;

        while (temp1 != nullptr && temp2 != nullptr) 
        {
            if (temp1->val <= temp2->val) 
            {
                temp->next = temp1;
                temp1 = temp1->next;
            } 
            else 
            {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }

        if (temp1 != nullptr) 
        {
            temp->next = temp1;
        } 
        else if (temp2 != nullptr) 
        {
            temp->next = temp2;
        }

        temp = dummyHead->next;
        delete dummyHead;
        return temp;
    }
};