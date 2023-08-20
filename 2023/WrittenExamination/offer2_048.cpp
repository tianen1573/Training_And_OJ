/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // 层序 保存 树数据
    string serialize(TreeNode* root) {
        
        if(root == nullptr)
            return string();
        string ret;
        queue<TreeNode*> que;
        que.push(root);

        while(que.size())
        {
            TreeNode *node = que.front();
            que.pop();

            if(node == nullptr)
            {
                ret += "#,";
            }
            else
            {
                ret += to_string(node->val) + ",";
                que.push(node->left);
                que.push(node->right);
            }
        }
        ret.pop_back();

        return ret;
    }

    // 层序 构建 树
    TreeNode* deserialize(string data) {
        
        if(data.empty())
            return nullptr;
        
        vector<TreeNode*> arr;
        for(int i = 0; i < data.size(); ++ i)
        {
            if(data[i] == '#')
            {
                arr.push_back(nullptr);
                ++ i;
            }
            else
            {
                string tmp = "";
                while(i < data.size() && data[i] != ',')
                {
                    tmp += data[i ++];
                }

                TreeNode *node = new TreeNode(stoi(tmp));
                arr.push_back(node);
            }
        }

        int pos = 1;
        for(int i = 0; i < arr.size(); ++ i)
        {
            if(arr[i] == nullptr)
                continue;
            
            arr[i]->left = arr[pos ++];
            arr[i]->right = arr[pos ++];
        }

        TreeNode *ret = arr[0];
        return ret;

        // return nullptr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));