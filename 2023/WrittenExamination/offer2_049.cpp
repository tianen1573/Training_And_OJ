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
class Solution {
public:
    int sum = 0;
    string number;
    int sumNumbers(TreeNode* root) {

        // 数字序列
        if(root)
        {
            number.push_back(root->val + '0');
        }

        // 叶子节点
        if(root->left == root->right)
        {
            // 转换
            sum += toint(number);
            number.pop_back(); // 出队
            return sum; // 仅作结束
        }
        else // 非叶子节点
        {
            // 遍历子树
            if(root->left) sumNumbers(root->left);
            if(root->right) sumNumbers(root->right);
            number.pop_back(); // 出队
            return sum; // 仅根节点有用
        }

    }
    int toint(string &tmp)
    {
        int num = 0;
        for(auto ch : tmp)
            num = num * 10 + (ch - '0');
        
        return num;
    }
};