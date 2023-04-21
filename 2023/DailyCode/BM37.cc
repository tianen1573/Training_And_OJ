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
    int p[10007], d[10007];//父，深

    void depth(TreeNode* root, int dep) {
        if (!root) return ; //空结点
        d[root->val] = dep;
        depth(root->left, dep + 1);
        depth(root->right, dep + 1);
    }
    int getFat(int x, int y) {

        if (d[y] > d[x]) return getFat(y, x); //默认x深
        while (d[x] > d[y]) x = p[x]; //将 x 提高到 和y 同一深度
        while (x != y) x = p[x], y = p[y]; //共同上升, 求公共父节点
        
        return x;
    }
    void dfs(TreeNode* root)
    {
        if(!root) return ;

        if(root->left) 
        {
            p[root->left->val] = root->val;
            dfs(root->left);
        }
        if(root->right)
        {
            p[root->right->val] = root->val;
            dfs(root->right);
        }
    }
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        // write code here
        dfs(root);
        depth(root, 1);

        return getFat(p, q);
    }
};