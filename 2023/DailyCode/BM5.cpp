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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode* head = new ListNode(-1);
        ListNode* cur = head;

        vector<ListNode*> vec;

        //先把空链表去除，注意迭代器失效问题
        bool flag = true;
        while (flag) {
            flag = false;
            for (int i = 0; i < lists.size(); i++) {
                if (nullptr == lists[i]) {
                    lists.erase(lists.begin() + i);
                    flag = true;
                    break;
                }
            }
        }


        while (!lists.empty()) {
            ListNode* minPtr;
            int minNum = INT_MAX;
            int minPos = -1;
            int i = 0;
            for (; i < lists.size(); i++) {
                if (lists[i]->val < minNum) {
                    minNum = lists[i]->val;
                    minPtr = lists[i];
                    minPos = i;
                }
            }
            cur->next = minPtr;
            cur = cur->next;

            lists[minPos] = lists[minPos]->next;
            //去除空链表
            if (nullptr == lists[minPos]) {
                lists.erase(lists.begin() + minPos);
            }

        }

        return head->next;

    }
};

//归并
class Solution {
public:
    //两个有序链表合并函数
    ListNode* Merge2(ListNode* pHead1, ListNode* pHead2) { 
        //一个已经为空了，直接返回另一个
        if(pHead1 == NULL) 
            return pHead2;
        if(pHead2 == NULL)
            return pHead1;
        //加一个表头
        ListNode* head = new ListNode(0); 
        ListNode* cur = head;
        //两个链表都要不为空
        while(pHead1 && pHead2){ 
            //取较小值的节点
            if(pHead1->val <= pHead2->val){ 
                cur->next = pHead1;
                //只移动取值的指针
                pHead1 = pHead1->next; 
            }else{
                cur->next = pHead2;
                //只移动取值的指针
                pHead2 = pHead2->next; 
            }
            //指针后移
            cur = cur->next; 
        }
        //哪个链表还有剩，直接连在后面
        if(pHead1) 
            cur->next = pHead1;
        else
            cur->next = pHead2;
        //返回值去掉表头
        return head->next; 
    }
    
    //划分合并区间函数
    ListNode* divideMerge(vector<ListNode *> &lists, int left, int right){ 
        if(left > right) 
            return NULL;
        //中间一个的情况
        else if(left == right) 
            return lists[left];
        //从中间分成两段，再将合并好的两段合并
        int mid = (left + right) / 2; 
        return Merge2(divideMerge(lists, left, mid), divideMerge(lists, mid + 1, right));
    }
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        //k个链表归并排序
        return divideMerge(lists, 0, lists.size() - 1); 
    }
};

//优先队列
class Solution {
public:
    struct cmp {
    //重载小顶堆比较方式
    bool operator()(ListNode* a, ListNode* b) { 
        return  a->val > b->val;  
    }
};
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        //小顶堆
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq; 
        //遍历所有链表第一个元素
        for(int i = 0; i < lists.size(); i++){ 
            //不为空则加入小顶堆
            if(lists[i] != NULL) 
                pq.push(lists[i]);
        }
        //加一个表头
        ListNode* res = new ListNode(-1); 
        ListNode* head = res;
        //直到小顶堆为空
        while(!pq.empty()){ 
            //取出最小的元素
            ListNode* temp = pq.top(); 
            pq.pop();
            //连接
            head->next = temp; 
            head = head->next;
            //每次取出链表的后一个元素加入小顶堆
            if(temp->next != NULL)
                pq.push(temp->next);
        }
        return res->next;
    }
};
