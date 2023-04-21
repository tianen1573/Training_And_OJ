
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:

    bool sym(TreeNode *a, TreeNode* b)
    {
        if(!a && !b) return true;
        if(!a || !b) return false;

        if(a->val != b->val) return false;

        return sym(a->left, b->right) && sym(a->right, b->left);
    }
    bool isSymmetrical(TreeNode* root) {
        
        if(!root) return true;

        return sym(root->left, root->right);
    }

};