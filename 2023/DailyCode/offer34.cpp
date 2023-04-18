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

    void dfs(TreeNode* root, vector<int>& vec, int sum, int target)//引用降低内存
    {
        if(!root->left && !root->right && sum == target)
        {
            ret.push_back(vec);
            return ;
        }

        if(root->left) 
        {
            vec.push_back(root->left->val);
            dfs(root->left, vec, sum + root->left->val, target);
            vec.pop_back();
        }
        if(root->right) 
        {
            vec.push_back(root->right->val);
            dfs(root->right, vec, sum + root->right->val, target);
            vec.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int> vec;
        
        if(!root) return vector<vector<int>>();

        vec.push_back(root->val);
        dfs(root, vec, root->val, target);


        return ret;

    }

    vector<vector<int>> ret;
};