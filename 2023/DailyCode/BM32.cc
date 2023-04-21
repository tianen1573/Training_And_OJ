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
     * @param t1 TreeNode类 
     * @param t2 TreeNode类 
     * @return TreeNode类
     */
    TreeNode* merge(TreeNode *t1, TreeNode *t2)
    {
        if(!t1 && !t2) return nullptr;
        else if(t1 && t2) {
            t1->val += t2->val;
            t1->left = merge(t1->left, t2->left);
            t1->right = merge(t1->right, t2->right);

            return t1;
        }
        else if(t1) {
            return t1;
        } 
        else {
            return t2;
        }
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        
        return merge(t1, t2);
    }
};