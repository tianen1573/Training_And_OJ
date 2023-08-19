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
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {

        queue<TreeNode*> que;
        que.push(root);

        while(true)
        {
            int size = que.size();
            TreeNode *head = que.front();

            for(int i = 0; i < size; ++ i)
            {
                TreeNode *node = que.front();
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }

            if(que.size() == 0)
            {
                return head->val;
            }
        }
    }
};