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
     * @return int整型vector
     */
    void post(TreeNode* cur) {
        if (!cur) return ;

        post(cur->left);
        post(cur->right);
        res.push_back(cur->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        // write code here
        post(root);

        return res;
    }

  private:
    vector<int> res;
};