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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;
        queue<TreeNode*> que;
        
        if(root) que.push(root);
        while(que.size())
        {
            int size = que.size();
            TreeNode *last = que.back();
            ans.push_back(last->val);

            for(int i = 0; i < size; ++ i)
            {
                TreeNode *node = que.front();
                que.pop();

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }

        return ans;
    }
};