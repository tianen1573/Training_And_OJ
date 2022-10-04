#define _CRT_SECURE_NO_WARNINGS 1

/*292单周塞*/
/* https://leetcode-cn.com/contest/weekly-contest-292/ */

/*6056. 字符串中最大的 3 位相同数字*/
/* https://leetcode-cn.com/problems/largest-3-same-digit-number-in-string/ */
//class Solution {
//public:
//    string largestGoodInteger(string num) {
//        int lag = 1;
//        char res = '\0';
//
//        for (int i = 1; i < num.size(); i++)
//        {
//
//            if (num[i] != num[i - 1])
//            {
//                lag = 1;
//            }
//            else
//                lag++;
//            if (lag == 3)
//            {
//                res = max(res, num[i]);
//            }
//        }
//
//        if (res == '\0')
//            return "";
//        string rel(3, res);
//        return rel;
//    }
//};

/*6057. 统计值等于子树平均值的节点数*/
/* https://leetcode-cn.com/problems/count-nodes-equal-to-average-of-subtree/ */
// /**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// * };
//  */
//
//int ChildNode(TreeNode* root)
//{
//    if (root == NULL)
//        return 0;
//    return 1 + ChildNode(root->left) + ChildNode(root->right);
//}
//int RootSum(TreeNode* root)
//{
//    if (root == NULL)
//    {
//        return 0;
//    }
//
//    int sum = root->val + RootSum(root->left) + RootSum(root->right);
//
//    return sum;
//}
//class Solution {
//public:
//    int averageOfSubtree(TreeNode* root) {
//
//        if (root == NULL)
//            return 0;
//
//        int sum = RootSum(root);
//        int ChildCount = ChildNode(root);
//
//        if (sum / ChildCount == root->val)
//            return 1 + averageOfSubtree(root->left) + averageOfSubtree(root->right);
//        else
//            return 0 + averageOfSubtree(root->left) + averageOfSubtree(root->right);
//    }
//};