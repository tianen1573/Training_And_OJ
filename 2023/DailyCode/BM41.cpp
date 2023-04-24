
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 求二叉树的右视图
     * @param xianxu int整型vector 先序遍历
     * @param zhongxu int整型vector 中序遍历
     * @return int整型vector
     */
    vector<int> ans;
    void bulid(vector<int>& pre, int l1, int r1, vector<int>& in, int l2, int r2, int dep) 
    {
        //终止条件
        if (l1 > r1 || l2 > r2) {
            return ;
        }

        //找根节点,切割左右子树
        int root = l2;
        while (root <= r2 && in[root] != pre[l1]) ++ root;

        //右视图，即每层最右边的节点，理论上应该都在右子树，先右后左，
        //则我们走到某一深度时，ans的大小应该等于深度
        //若右子树符合，则回溯递归的左子树时，ans的大小是大于等于深度的
        //不满足，即代表该左子树没有兄弟右子树，它就是最右节点
        if(dep > ans.size()) ans.push_back(pre[l1]);
        //分割左右子树
        bulid(pre, l1 + root - l2 + 1, r1, in, root + 1, r2, dep + 1);
        bulid(pre, l1 + 1, l1 + root - l2, in, l2, root - 1, dep + 1);
    }
    vector<int> solve(vector<int>& xianxu, vector<int>& zhongxu) {
        // write code here

        bulid(xianxu, 0, xianxu.size() - 1, zhongxu, 0, zhongxu.size() - 1, 1);

        return ans;
    }
};