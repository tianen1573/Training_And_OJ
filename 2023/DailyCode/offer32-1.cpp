/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {

        vector<int> res;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty())
        {
            auto node= que.front();
            que.pop();
            if(node)
            {
                res.push_back(node->val);
                que.push(node->left);
                que.push(node->right);
            }
        }

        return res;

    }
};