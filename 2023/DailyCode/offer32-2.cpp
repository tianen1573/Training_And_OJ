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
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(!root) return vector<vector<int> >();

        vector< vector<int> > res;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty())
        {
            int len = que.size();
            vector<int> arr;
            while(len --)
            {
                auto node= que.front();
                que.pop();

                arr.push_back(node->val);
                if(node->left)  que.push(node->left);
                if(node->right) que.push(node->right);
            }
            res.push_back(arr);
           
        }

        return res;

    }
};