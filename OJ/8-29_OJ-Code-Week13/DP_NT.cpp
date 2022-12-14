#define _CRT_SECURE_NO_WARNINGS 1

#include<bits/stdc++.h>
using namespace std;



/*1359. 有效的快递序列数目*/
/* https://leetcode.cn/problems/count-all-valid-pickup-and-delivery-options/ */


/* dp[i][j] 为 待收为i, 待送为j 的个数
* 则dp[i][j] 可以更新 dp[i-1][j] 和 dp[i][j-1];
* 将dp[i][j]优化为 dp[j], j为待送的个数, 用 for循环成员i 来代替 待收件
* 则dp[j] 可以更新 dp[j + 1](i - 1) 和 dp[j - 1](i);
* 最后dp[0]或者dp[1] 就是方案数
*/

class Solution {
public:
   int countOrders(int n)
   {
       const int MOD = 1e9 + 7;
       int col = 0, row = n;
       vector<int> dp(n + 1, 0);
       dp[0] = 1;
       for (long long i = row; i > 0; i--)
       {
           vector<int> newdp(n + 1, 0);
           for (long long j = col; j >= 1; j--)
           {
               newdp[j + 1] = dp[j] * i % MOD;
               dp[j - 1] = (dp[j - 1] + dp[j] * j) % MOD;
           }

           newdp[1] = dp[0] * i % MOD;
           col++;
           dp = newdp;
       }
       for (long long j = col; j >= 1; j--)
           dp[j - 1] = (dp[j - 1] + dp[j] * j) % MOD;
       return dp[0];
   }
};
