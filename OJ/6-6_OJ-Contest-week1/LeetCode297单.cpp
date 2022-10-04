#define _CRT_SECURE_NO_WARNINGS 1

/* https://leetcode.cn/contest/biweekly-contest-80/ */

/* 纳税额 */
//class Solution {
//public:
//    double calculateTax(vector<vector<int>>& brackets, int income) {
//
//        int tmp = income, i = 0; double money = 0.0;
//
//        for (i = 0; i < brackets.size(); i++)
//        {
//            if (income >= brackets[i][0])
//            {
//                if (i == 0)
//                {
//                    money += brackets[0][0] * 0.01 * brackets[0][1];
//                    tmp -= brackets[0][0];
//                }
//                else
//                {
//                    money += (brackets[i][0] - brackets[i - 1][0]) * 0.01 * brackets[i][1];
//                    tmp -= (brackets[i][0] - brackets[i - 1][0]);
//                }
//            }
//            else
//            {
//                money += tmp * 0.01 * brackets[i][1];
//                break;
//            }
//        }
//
//        return money;
//    }
//};

/* 最小路径 */
//class Solution {
//public:
//
//    int min(int a, int b)
//    {
//        if (a > b) return b;
//        else return a;
//    }
//
//    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
//        int m = grid.size(), n = grid[0].size();
//        vector<int> ans, tmp;
//        for (int i = 0; i < n; i++)
//        {
//            ans.push_back(0);
//            tmp.push_back((int)(1e9 + 7));
//        }
//
//        for (int i = 1; i < m; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                tmp[j] = ans[0] + grid[i - 1][0] + moveCost[grid[i - 1][0]][j];
//                for (int k = 0; k < n; k++)
//                {
//                    tmp[j] = min(tmp[j], ans[k] + grid[i - 1][k] + moveCost[grid[i - 1][k]][j]);
//                }
//            }
//            ans = tmp;
//        }
//        int ret = ans[0] + grid[m - 1][0];
//        for (int i = 0; i < n; i++)
//            ret = min(ret, ans[i] + grid[m - 1][i]);
//
//        return ret;
//    }
//};