// 带重复节点的前序中序二叉树
// 已知一个二叉树的先序遍历序列和中序遍历序列，但其中一些节点的值可能相同。
// 请你返回所有满足条件的二叉树。二叉树在数组中的顺序是任意的。


/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> bulidTree(vector<int>& preOrder, vector<int>& inOrder, int idx, int left, int rig)
    {
        vector<TreeNode*> ret;
        for(int i = left; i <= rig; ++ i)
        {
            if(preOrder[idx] == inOrder[i])
            {
                vector<TreeNode*> leftArr = bulidTree(preOrder, inOrder, idx + 1, left, i - 1);
                vector<TreeNode*> rigArr = bulidTree(preOrder, inOrder, idx + (i - left + 1), i + 1, rig);
                
                // 如果数组为空， 说明无法构成左右子树
                // 违法构建，直接跳过
                if(leftArr.empty() || rigArr.empty())
                    continue;
                for(auto leftNode : leftArr)
                    for(auto rigNode : rigArr)
                    {
                        TreeNode *node = new TreeNode(preOrder[idx]);
                        node->left = leftNode;
                        node->right = rigNode;
                        ret.push_back(node);
                    }
            }
        }
        if(left > rig) ret.push_back(nullptr); // 空集填充一个空指针

        return ret;
    }
    vector<TreeNode*> getBinaryTrees(vector<int>& preOrder, vector<int>& inOrder) {
        
        return bulidTree(preOrder, inOrder, 0, 0, preOrder.size() - 1);
    }
};