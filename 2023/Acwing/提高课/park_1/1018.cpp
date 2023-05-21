//2n - 1: 限制了只能向右向左

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 111;

int f[N][N];

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    memset(f, 0x3f, sizeof f);
    f[0][1] = f[1][0] = 0;//特殊处理
    cin >> n;
    
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= n; ++ j) cin >> f[i][j];
        
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= n; ++ j)
            f[i][j] += min(f[i][j - 1], f[i - 1][j]);
    
    cout << f[n][n];
    
    return 0;
}