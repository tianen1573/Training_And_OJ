/**
 * struct TreeNode {
 *  int val;
 *  struct TreeNode *left;
 *  struct TreeNode *right;
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return bool布尔型
     */
    bool isCompleteTree(TreeNode* root) {
        // write code here

        queue<TreeNode*> que;

        que.push(root);

        while (!que.empty()) {
            auto cur = que.front();
            que.pop();

            if (!cur) {
                while (!que.empty()) {
                    auto curr = que.front();
                    que.pop();
                    if (curr) return false;
                }
            } else {
                que.push(cur->left);
                que.push(cur->right);
            }

        }


        return true;
    }
};