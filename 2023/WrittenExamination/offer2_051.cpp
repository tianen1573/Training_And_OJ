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

    int maxVal = INT_MIN;
    int inorderMax(TreeNode* root)
    {
        // 求左右子树
        int maxL = root->left ? inorderMax(root->left) : INT_MIN;
        int maxR = root->right ? inorderMax(root->right) : INT_MIN;
        // 求当前树的值, 更新最大值
        int curVal = root->val;
        if(maxL > 0) curVal += maxL;
        if(maxR > 0) curVal += maxR;
        maxVal = max(maxVal, curVal);
        // 返回给父节点
        curVal = root->val;
        int maxLR = max(max(maxL, maxR), 0); // 左右子树最多取一个
        curVal += maxLR;
        return curVal;
    }
    int maxPathSum(TreeNode* root) {

        inorderMax(root);
        return maxVal;
    }
};