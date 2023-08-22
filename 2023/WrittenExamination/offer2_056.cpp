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

    // 类似有序数组双指针
    bool _findTarget(TreeNode *left, TreeNode *rig, int tar)
    {
        if(!left || !rig)
            return false;
        
        if(left == rig)
        {
            if(left->val + left->val > tar)
                return _findTarget(left->left, left, tar);
            else
                return _findTarget(left, left->right, tar);
        }
        if(left->val + rig->val == tar)
            return true;
        else if(left->val + rig->val > tar)
            return _findTarget(left->left, rig, tar) || _findTarget(left, rig->left, tar);
        else
            return _findTarget(left->right, rig, tar) || _findTarget(left, rig->right, tar);
    }
    // hash
    unordered_set<int> hash;
    int tar;
    bool _findTargetHash(TreeNode *root)
    {
        if(root == nullptr)
            return false;
        
        if(hash.count(tar - root->val) == 1)
            return true;
        hash.insert(root->val);
        if(_findTargetHash(root->left))
            return true;
        if(_findTargetHash(root->right))
            return true;

        return false;
    }
    bool findTarget(TreeNode* root, int k) {

        // return _findTarget(root, root, k);

        tar = k;
        return _findTargetHash(root);
    }
};