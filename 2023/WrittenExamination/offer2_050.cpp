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
    int cnt = 0;
    int tarSum;
    void CalPriSum(TreeNode* root, vector<long long> &arr)
    {
        // 前缀和
        arr.push_back(arr.back() + root->val);
        // 计算前缀和差
        int len = arr.size();
        for(int i = 0; i < len - 1; ++ i)
        {
            if(arr[len - 1] - arr[i] == tarSum)
             ++ cnt;
        }

        if(root->left) CalPriSum(root->left, arr);
        if(root->right) CalPriSum(root->right, arr);
        arr.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        
        if(root == nullptr)
            return 0;
        
        tarSum = targetSum;
        CalPriSum(root, vector<long long>()={0});

        return cnt;
    }
};