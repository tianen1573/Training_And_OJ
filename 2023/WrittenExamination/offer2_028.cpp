/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    // 递归版
    Node* childNode(Node* head)
    {
        if(head == nullptr) return head;
        Node *cur = head;
        while(cur->child || cur->next)
        {
            if(cur->child)
            {
                Node *next = cur->next; // 保存next节点
                cur->next = cur->child; // 将cur->next指向其child节点
                cur->child->prev = cur; // 同样的将其child的pre指向cur
                cur->child = nullptr; // 置空

                Node *tail = childNode(cur->next); // 子链表的尾节点
                tail->next = next; // 尾节点的next指向原先的next
                if(next) next->prev = tail; // 若next存在，则改变其prev的指向
            }
            if(cur->next)
                cur = cur->next;
        }
        return cur; // 返回的是每行链表尾节点
    }
    Node* flatten(Node* head) {
        
        // 迭代
        Node *cur = head;
        while(cur)
        {
            if(cur->child)
            {
                Node *next = cur->next; // 保存next节点
                cur->next = cur->child; // 将cur->next指向其child节点
                cur->child->prev = cur; // 同样的将其child的pre指向cur
                // 遍历到child这一列的尾节点
                Node *tail = cur->next;
                while(tail->next)
                    tail = tail->next;
                tail->next = next; // 尾节点的next指向原先的next
                if(next) next->prev = tail; // 若next存在，则改变其prev的指向
                cur->child = nullptr; // 置空
            }
            cur = cur->next; // 枚举下一个
        }

        // childNode(head);

        return head;
    }
};