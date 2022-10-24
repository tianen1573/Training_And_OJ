
/*https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/*/
/*最近公共祖先*/

// 1. 两个节点必是 LCA 的 左右孩子
// 2. 用 递归+栈， 得到路径， 转换为 链表相交问题
// 3. map<节点地址，{父节点地址， 高度}>

class Solution {
public:
    bool FindPath(TreeNode* root, TreeNode* x, stack<TreeNode*>& path)
    {
        if(root == nullptr)
        {
            return false;
        }
        path.push(root);
        if(root == x)
        {    
            return true;
        }

        if(FindPath(root->left, x, path) || FindPath(root->right, x, path))
        {
            return true;
        }
        else
        {
            path.pop();
            return false;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        stack<TreeNode*> pPath, qPath;
        FindPath(root, p, pPath);
        FindPath(root, q, qPath);

        while(pPath.size() != qPath.size())
        {
            if(pPath.size() > qPath.size())
            {
                pPath.pop();
            }
            else{
                qPath.pop();
            }
        }

        while(pPath.top() != qPath.top())
        {
            pPath.pop();
            qPath.pop();
        }

        TreeNode* res = pPath.top();
        return res;

    // 
    }
};