/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > levelOrder(TreeNode* root) {

        if(!root) return vector<vector<int> >();
        // write code here
        vector<vector<int> > res;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty())
        {
            int len = que.size();
            vector<int> arr;
            while(len --)
            {
                auto cur = que.front();//指针类型， auto 等价于 auto*
                que.pop();

                arr.push_back(cur->val);
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            res.push_back(arr);
        }

        return res;
        
    }
};