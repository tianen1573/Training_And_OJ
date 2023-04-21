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
    
    //记录每棵树的最大值最小值，左为最大，右为最小
    vector<int> BST(TreeNode* root) {

        if(!root) return vector<int>() = {INT_MIN, INT_MAX};//左大右小


        vector<int> LeftArr = BST(root->left);//左子树的最大最小
        vector<int> RigArr = BST(root->right);//右子树的

        vector<int> arr(2);
        if(root->val > LeftArr[0] && root->val < RigArr[1])//满足BST
        {
            arr[0] = max(root->val, RigArr[0]);//更新最大值
            arr[1] = min(root->val, LeftArr[1]);//更新最小值

            return arr;
        }
        else {
            return vector<int>() = {INT_MAX, INT_MIN};
        }

    }
    bool isValidBST(TreeNode* root) {

        vector<int> LeftArr = BST(root->left);
        vector<int> RigArr = BST(root->right);
        
        return (root->val > LeftArr[0] && root->val < RigArr[1]);
    }
};

//中序遍历 + 栈，判断出栈时，是否为降序