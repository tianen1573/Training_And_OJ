/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
public:
    queue<TreeNode*> que;
    int childCnt = 0;
    TreeNode *Root;
    CBTInserter(TreeNode* root) {
        Root = root;
        que.push(root);
        // 先把节点入队
        while(true)
        {
            // 本层为 最后一个满节点的 层
            TreeNode *tail = que.back();    
            if(!tail->left || !tail->right) //最后一个节点没有两个孩子，则该层就满足上述条件
                break;
            // 遍历该层
            int size = que.size();
            for(int i = 0; i < size; ++ i)
            {
                // 走到这里的都是两个孩子的节点
                TreeNode *node = que.front();
                que.pop();

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        // 把两个孩子的节点 出队
        while(true)
        {
            TreeNode *head = que.front();
            childCnt = 0;
            if(head->right)
            {
                que.push(head->left);
                que.push(head->right);
                que.pop();
                childCnt = 0;

                continue; 
            }
            else if(head->left)
            {
                que.push(head->left);
                childCnt = 1;
            }

            break;
        }
        
    }
    
    int insert(int v) {

        // 新节点入队
        TreeNode *newNode = new TreeNode(v);
        que.push(newNode);

        // 找爸爸
        TreeNode *head = que.front();
        if(childCnt == 0) // 一个儿子
        {
            head->left = newNode;
            ++ childCnt;
        }
        else if(childCnt == 1) // 两个儿子
        {
            head->right = newNode;
            childCnt = 0;
            que.pop();
        }

        return head->val;
    }
    
    TreeNode* get_root() {

        return Root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */