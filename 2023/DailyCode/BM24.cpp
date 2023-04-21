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
    void in(TreeNode* cur) {
        if (!cur) return ;

        in(cur->left);
        res.push_back(cur->val);
        in(cur->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        // write code here
        in(root);

        return res;
    }
  private:
    vector<int> res;
};