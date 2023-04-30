class Solution {
  public:
    char* Serialize(TreeNode* root) {

        if (root == nullptr) return "";

        string res;

        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            auto cur = que.front();
            que.pop();

            if (cur == nullptr) {
                res += "#,";
            } else {
                res += (to_string(cur->val) + ',');
                que.push(cur->left);
                que.push(cur->right);
            }
        }

        char* str = new char[res.size() + 1];
        for (int i = 0; i < res.size(); ++ i) {
            str[i] = res[i];
        }
        str[res.size()] = '\0';
        return str;
    }
    TreeNode* Deserialize(char* str) {

        string data(str);

        if (data.empty()) return nullptr;

        vector<TreeNode*> vec;
        int len = data.size();

        for (int i = 0; i < len; ++ i) {
            string val = "";
            while (data[i] != ',')
                val += data[i++];

            if (val == "#")
                vec.push_back(nullptr);
            else {
                auto nodePtr = new TreeNode(stoi(val));
                vec.push_back(nodePtr);
            }
        }

        int pos = 1;
        for (int i = 0; i < vec.size(); ++ i) {
            if (vec[i] == nullptr) continue;

            vec[i]->left = vec[pos++];
            vec[i]->right = vec[pos++];
        }

        return vec[0];
    }
};
