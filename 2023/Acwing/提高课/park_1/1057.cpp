//f[i,j,k]：第i天时，进行了j笔交易，股票状态为k(1,0)时 的 最大价值， 记买入时交易数+1
//f[i,j,0] = max(f[i-1,j,0], f[i-1,j,1] + wi)
//f[i,j,1] = max(f[i-1,j,1], f[i-1,j-1,0] - wi)

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 11, M = 111;

int f[2][M][2];

int n, k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    
    memset(f, -0x3f, sizeof f);
    for (int i = 0; i <= 1; i ++ ) f[i][0][0] = 0;//j为0时，k为1是不存在的状态
    
    for(int i = 1; i <= n; ++ i)
    {
        int val; cin >> val;
        
        for(int j = 1; j <= k; ++ j)
        {
            f[i & 1][j][0] = max(f[(i - 1) & 1][j][0], f[(i - 1) & 1][j][1] + val);
            f[i & 1][j][1] = max(f[(i - 1) & 1][j][1], f[(i - 1) & 1][j - 1][0] - val);
        }
    }
    
    int res = 0;
    for(int i = 0; i <= k; ++ i)
    {
        res = max(res, f[n & 1][i][0]);
    }
    cout << res;
    
    return 0;
}
