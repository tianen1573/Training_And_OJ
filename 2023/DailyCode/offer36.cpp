/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {

        if(!root) return nullptr;

        Node *head = nullptr, *prev = nullptr;
        Node *cur = root;

        stack<Node*> stk;

        while(cur || !stk.empty())
        {
            while(cur)
            {
                stk.push(cur);
                cur = cur->left;
            }

            auto top = stk.top();
            stk.pop();

            if(head == nullptr)
            {
                head = top;
                head->left = nullptr;
            }
            if(prev)
            {
                prev->right = top;
                top->left = prev;
            }

            prev = top;

            cur = top->right;
        }

        //处理头尾
        head->left = prev;
        prev->right = head;

        return head;
        
    }
};