
/* https://leetcode.cn/problems/maximum-depth-of-binary-tree/submissions/ */
/*������������*/

class Solution {
public:
    int maxDepth(TreeNode* root) {

        if(root == NULL)
        {
            return 0;
        }

        return 1 + max(maxDepth(root->left), maxDepth(root->right));

    }
};

/* https://leetcode.cn/problems/univalued-binary-tree/submissions/ */
/*��ֵ������*/

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {

        if(root == NULL)
        {
            return true;
        }
        if(root->left && root->val != root->left->val)
        {
            return false;
        }
        if(root->right && root->val != root->right->val)
        {
            return false;
        }
        
        return isUnivalTree(root->left) && isUnivalTree(root->right);

    }
};