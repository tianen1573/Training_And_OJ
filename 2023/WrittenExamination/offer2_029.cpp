/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        
        // 1. 空结点
        if(head == nullptr)
        {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        // 找到最小节点/最大节点
        // 当最大值有多个时，可以通过>=找到最右边的那个
        // 当head切入位置不能确定，所以最小值的位置通过maxV->next确定
        // 至此，minV到maxV 是一个不严谨的升序链表
        Node *cur = head, *maxV = nullptr, *minV = nullptr;
        while(cur)
        {
            if(maxV == nullptr || cur->val >= maxV->val)
                maxV = cur;          
            cur = cur->next;
            if(cur == head) break;
        }
        minV = maxV->next;
        // 2. 最小或最大
        // 都是放到maxV后面
        if(insertVal >= maxV->val || insertVal <= minV->val)
        {
            Node *node = new Node(insertVal);
            node->next = minV;
            maxV->next = node;
            return head;
        }
        // 3. 在中间
        // 我们已经将链表处理成了一个升序链表，直接遍历求
        cur = minV->next;
        Node *prev = minV;
        while(cur->val < insertVal)
        {
            prev = cur;
            cur = cur->next;
        }
        Node *node = new Node(insertVal);
        node->next = prev->next;
        prev->next = node;
        return head;
        
        return nullptr;
    }
};