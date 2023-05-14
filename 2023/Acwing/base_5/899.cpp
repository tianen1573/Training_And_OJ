#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1010;

char arr[N][13];

int n, m;

int minDist(char A[], char B[])
{
    int dp[13][13];
    for(int i = 0; i <= 13; ++ i) dp[0][i] = i;
    for(int i = 0; i <= 13; ++ i) dp[i][0] = i;
    
    int La = 0, Lb = 0;
    while(*(A + ++La)); La--;
    while(*(B + ++Lb)); Lb--;
    
    
    for(int i = 1; i <= La; ++ i)
        for(int j = 1; j <= Lb; ++ j)
        {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
            
            if(A[i] == B[j]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            else dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
        }
    
    return dp[La][Lb];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i) cin >> arr[i] + 1;
    
    while(m --)
    {
        int k;
        char tmp[13]; 
        cin >> tmp + 1 >> k;
        
        int cnt = 0;
        for(int i = 1; i <= n; ++ i)
        {
            if(minDist(tmp, arr[i]) <= k) cnt++;
        }
            
        cout << cnt << endl;
    }
    
    return 0;
}