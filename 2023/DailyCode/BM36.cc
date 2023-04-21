class Solution {
public:

    int depth(TreeNode* root)
    {
        if(!root) return 0;

        int left = depth(root->left);
        if(-1 == left) return -1;
        int rig = depth(root->right);
        if(-1 == rig) return -1;

        return abs(left - rig) < 2 ? max(left, rig) + 1 : -1;
    }

    bool IsBalanced_Solution(TreeNode* root) {

        return depth(root) != -1;
    }
};