/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:

//     vector<int> res;

//     void preOrder(TreeNode* root)
//     {
//         if(root == NULL)
//         {
//             return;
//         }

//         res.push_back(root->val);
//         preOrder(root->left);
//         preOrder(root->right);

//     }

//     vector<int> preorderTraversal(TreeNode* root) {

//         preOrder(root);

//         return res;

//     }
// };
class Solution {
public:
vector<int> preorderTraversal(TreeNode* root) {

    stack<TreeNode*> st;
    vector<int> v;
    TreeNode* cur = root;
    while(cur || !st.empty())
    {
    // 开始访问一棵树
    //1、左路节点
        while(cur)
        {
            st.push(cur);
            v.push_back(cur->val);
            cur = cur->left;
        }

        // 2、左路节点的右子树需要访问
        TreeNode* top = st.top();
        st.pop();
        
        cur = top->right; // 子问题访问右子树
    }

    return v;
    }
};