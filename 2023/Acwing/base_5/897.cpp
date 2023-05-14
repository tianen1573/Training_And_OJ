/*
1. https://www.bilibili.com/video/BV14A411v7mP/?vd_source=a8c846cf3f5a0585b3f2960af8729db0
2. 题解
f[i][j]:从 字符串A的前i个，字符串B的前j个 选出的最长子序列的长度
f[i][j] = max{f[i - 1][j - 1], f[i-1][j-1], f[i-1][j], f[i-1][j-1] + 1(if a[i] == b[j])}, f[i - 1][j - 1]在前两个集合里，可以舍弃
*/

#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1010;

int dp[N][N];
char A[N], B[N];

int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    cin >> A + 1 >> B + 1;
    
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(A[i] == B[j])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
        
    cout << dp[n][m];
    
    return 0;
}