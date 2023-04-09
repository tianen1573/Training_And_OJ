class Solution {
public:

    void mirror(TreeNode* root)
    {
        if(!root) return ;

        swap(root->left, root->right);

        mirror(root->left);
        mirror(root->right);
    }
    TreeNode* mirrorTree(TreeNode* root) {

        mirror(root);

        return root;

    }
};