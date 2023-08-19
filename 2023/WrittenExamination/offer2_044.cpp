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
    vector<int> largestValues(TreeNode* root) {

        if(root == nullptr) return vector<int>();
        
        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);

        while(que.size())
        {
            int size = que.size();
            int maxVal = INT_MIN;

            for(int i = 0; i < size; ++ i)
            {
                TreeNode *node = que.front();
                que.pop();

                maxVal = max(maxVal, node->val);

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }

            ans.push_back(maxVal);
        }

        return ans;
    }
};