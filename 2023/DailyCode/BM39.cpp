class Solution {
  public:
    char* Serialize(TreeNode* root) {
        if (root == nullptr) {
            return "#,";
        }
        string res;
        size_t nullCount = 0;
        queue<TreeNode*> qu;
        qu.push(root);
        while (qu.size() != nullCount) {
            TreeNode* p = qu.front();
            res += visitNodeStr(p);
            qu.pop();
            if (p != nullptr) {
                qu.push(p->left);
                qu.push(p->right);
                if (p->left == nullptr)nullCount++;
                if (p->right == nullptr)nullCount++;
            } else {
                qu.push(nullptr);
                qu.push(nullptr);
                nullCount++;
            }
        }
        char* ret = new char[res.length() + 2];
        int i = 0;
        for (; i < res.length(); i++)
            ret[i] = res[i];
        ret[i] = '\0';
        return ret;
    }
    TreeNode* Deserialize(char* str) {
        if (str == nullptr) {
            return nullptr;
        }
        string s(str);
        if (str[0] == '#') {
            return nullptr;
        }
        vector<TreeNode*> v;
        TreeNode* ret = new TreeNode(atoi(s.c_str()));
        v.push_back(ret);
        s = s.substr(s.find_first_of(',') + 1);
        while (!s.empty()) {
            if (s[0] == '#') {
                v.push_back(nullptr);
                s = s.substr(2);
            } else {
                TreeNode* n = new TreeNode(atoi(s.c_str()));
                v.push_back(n);
                s = s.substr(s.find_first_of(',') + 1);
            }
        }
        size_t i = 0, sz = v.size();
        while ((i + 1) * 2 - 1 < sz) {
            if (v[i] == nullptr) {
                i++;
                continue;
            }
            v[i]->left = v[(i + 1) * 2 - 1];
            v[i]->right = v[(i + 1) * 2];
            i++;
        }
        return v[0];
    }
    string visitNodeStr(TreeNode* p) {
        if (p == nullptr)return "#,";
        else return to_string(p->val) + ",";
    }
};
