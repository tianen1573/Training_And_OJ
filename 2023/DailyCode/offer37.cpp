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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if(root == nullptr) return "";

        string res;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty())
        {
            auto cur = que.front();
            que.pop();

            if(cur == nullptr)
            {
                res += "#,";
            }
            else
            {
                res += (to_string(cur->val) + ',');
                que.push(cur->left);
                que.push(cur->right);
            }
        }

        return res;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if(data.empty()) return nullptr;

        vector<TreeNode*> vec;
        int len = data.size();

        for(int i = 0; i < len; ++ i)
        {
            string val = "";
            while(data[i] != ',')
                val += data[i++];
            
            if(val == "#")
                vec.push_back(nullptr);
            else
            {
                auto nodePtr = new TreeNode(stoi(val));
                vec.push_back(nodePtr);
            }
        }
        
        int pos = 1;
        for(int i = 0; i < vec.size(); ++ i)
        {
            if(vec[i] == nullptr) continue;

            vec[i]->left = vec[pos++];
            vec[i]->right = vec[pos++];
        }

        return vec[0];

    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));