class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> st; // 保存访问节点
        TreeNode *prev = nullptr, *curr = root;
        
        //  当前仅当栈为空， 且curr为空时， 所以节点才访问完
        while (!st.empty() || curr != nullptr) 
        {
            while (curr != nullptr) 
            {
                // 遍历至该树的最左节点
                st.emplace(curr);
                curr = curr->left;
            }
            // 取出一个节点
            curr = st.top();
            st.pop();
            // 判断
            if (prev == p) 
            {
                return curr;
            }
            // 更新下个节点的父节点
            prev = curr;
            // 访问右子树
            curr = curr->right;
        }
        
        return nullptr;
    }
};