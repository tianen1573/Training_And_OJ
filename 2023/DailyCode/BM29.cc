/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return bool布尔型
     */
    bool fun(TreeNode* root, int sum, int tar)
    {

        if(!root->left && !root->right) return sum + root->val == tar;

        bool flag = false;
        if(root->left) flag |=  fun(root->left, sum + root->val, tar);
        if(root->right) flag |= fun(root->right, sum + root->val, tar);

        return flag;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        // write code here
        if(!root) return false;
        return fun(root, 0, sum);
    }
};