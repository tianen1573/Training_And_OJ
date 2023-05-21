#include <cstdio>
#include <iostream>

#include <cstring>

using namespace std;

const int N = 551;

int n;

int dp[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    memset(dp, 0xdf, sizeof dp);//初始化
    
    
    cin >> n;
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j<= i; ++ j)
            cin >> dp[i][j];
            
    
    for(int i = 2; i <= n; ++ i)
        for(int j = 1; j <= i; ++ j)
            dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
    
    int res = -1e9;
    
    for(int i = 1; i <= n; ++ i)
        res = max(res, dp[n][i]);
        
    cout << res;
    
    return 0;
}