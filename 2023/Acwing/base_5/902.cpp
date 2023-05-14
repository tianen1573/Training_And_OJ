/*
f[i][j] = min{
f[i - 1][j] + 1 : A的前i-1操作后能和B的前j匹配，则只能把i删了，删
f[i][j - 1]: 只能给A加一个B[j]，增
f[i -1][j - 1] : 如果A[i] != B[j], 需要改A[i]，即+1， 否则不变
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
    
    cin >> n; cin >> A + 1;
    cin >> m; cin >> B + 1;
    
    for(int i = 0; i <= m; ++ i) dp[0][i] = i;
    for(int i = 0; i <= n; ++ i) dp[i][0] = i;
    
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
        {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
            
            if(A[i] == B[j]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            else dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
        }
        
    cout << dp[n][m];
    
    return 0;
}