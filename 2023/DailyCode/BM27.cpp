
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
  public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        if (!pRoot) return  vector<vector<int> >();

        vector<vector<int> > res;

        deque<TreeNode*> deq;

        int flag = 1;
        deq.push_back(pRoot);


        while (!deq.empty()) {
            int len = deq.size();
            vector<int> arr;

            while (len --) {
                if (flag == 1) {
                    auto cur = deq.front();
                    deq.pop_front();
                    arr.push_back(cur->val);

                    if (cur->left) deq.push_back(cur->left);
                    if (cur->right) deq.push_back(cur->right);
                } else {
                    auto cur = deq.back();
                    deq.pop_back();

                    arr.push_back(cur->val);

                    if (cur->right) deq.push_front(cur->right);
                    if (cur->left) deq.push_front(cur->left);
                }
            }

            res.push_back(arr);
            flag *= -1;
        }


        return res;

    }

};