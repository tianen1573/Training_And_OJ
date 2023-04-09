class Solution {
public:

    bool sym(TreeNode *A, TreeNode *B)
    {
        if(!A && !B) return true;
        if(!A || !B) return false;

        if(A->val != B->val) return false;

        return sym(A->left, B->right) && sym(A->right, B->left);
    }
    bool isSymmetric(TreeNode* root) {

        if(!root) return true;

        return sym(root->left, root->right);

    }
};