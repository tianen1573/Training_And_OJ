
/* https://leetcode.cn/problems/maximum-depth-of-binary-tree/submissions/ */
/*二叉树最大深度*/

class Solution {
public:
    int maxDepth(TreeNode* root) {

        if(root == NULL)
        {
            return 0;
        }

        return 1 + max(maxDepth(root->left), maxDepth(root->right));

    }
};

/* https://leetcode.cn/problems/univalued-binary-tree/submissions/ */
/*单值二叉树*/

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {

        if(root == NULL)
        {
            return true;
        }
        if(root->left && root->val != root->left->val)
        {
            return false;
        }
        if(root->right && root->val != root->right->val)
        {
            return false;
        }
        
        return isUnivalTree(root->left) && isUnivalTree(root->right);

    }
};

// https://leetcode.cn/problems/construct-string-from-binary-tree/submissions/
class Solution {
private:
    string res;
public:
    void mytree(TreeNode* root)
    {
        if(root == nullptr)
        {
            return ;
        }
        res += to_string(root->val);

        if(root->left || root->right)
        {
            res += '(';
            mytree(root->left);
            res += ')';
        }
        if(root->right)
        {
            res += '(';
            mytree(root->right);
            res += ')';
        }

        return;
    }
    string tree2str(TreeNode* root) {
        
        mytree(root);

        return res;
    }
};

// https://leetcode.cn/problems/binary-tree-level-order-traversal/submissions/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(root == nullptr)
        {
            return vector<vector<int>>();
        }

        vector<vector<int>> res;
        queue<TreeNode*> que;

        que.push(root);

        while(!que.empty())
        {
            int _size = que.size();
            vector<int> tmp;

            while(_size --)
            {
                TreeNode* cur = que.front();
                que.pop();

                tmp.push_back(cur->val);

                if(cur->left)
                {
                    que.push(cur->left);
                }
                if(cur->right)
                {
                    que.push(cur->right);
                }
            }

            res.push_back(tmp);
        }

        return res;

    }
};