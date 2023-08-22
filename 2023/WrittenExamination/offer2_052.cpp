class Solution {
private:
    TreeNode *resNode;

public:
    void inorder(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        // 左
        inorder(node->left);
        // 中
        // 在中序遍历的过程中修改节点指向
        resNode->right = node;
        node->left = nullptr;
        resNode = node;
        // 右
        inorder(node->right);
    }

    TreeNode *increasingBST(TreeNode *root) {
        TreeNode *dummyNode = new TreeNode(-1);
        resNode = dummyNode;
        inorder(root);
        
        TreeNode * ret = dummyNode->right;
        delete dummyNode;
        return ret;
    }
};