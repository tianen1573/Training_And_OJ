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

    void pre(TreeNode *cur)
    {
        if(!cur) return ;

        res.push_back(cur->val);
        pre(cur->left);
        pre(cur->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        
        pre(root);

        return res;
    }
  private:
    vector<int> res;
};