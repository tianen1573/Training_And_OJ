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
    TreeNode* bulid(vector<int>& pre, int l1, int r1, vector<int>& in, int l2, int r2)
    {
        //终止条件
        if(l1 > r1 || l2 > r2)
        {
            return nullptr;
        }

        //找根节点
        int root = l2;
        while(root <= r2 && in[root] != pre[l1]) ++ root;

        //分割左右子树
        auto cur = new TreeNode(pre[l1]);
        cur->left = bulid(pre, l1 + 1, l1 + root - l2, in, l2, root - 1);
        cur->right = bulid(pre, l1 + root - l2 + 1, r1, in, root + 1, r2);
        return cur;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        return bulid(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);

    }
};