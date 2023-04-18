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

    void inorder(TreeNode* root, int &pos, const int k, int& val)
    {


        if (root->right) inorder(root->right, pos, k, val);

        ++ pos;
        if(pos == k) val = root->val;

        if (root->left) inorder(root->left, pos, k, val);

    }
    int kthLargest(TreeNode* root, int k) {
        int pos = 0, val = 0;

        inorder(root, pos, k, val);

        return val;
    }
};