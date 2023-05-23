#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010, M = 510, K = 110;//精灵球，体力值，精灵数量

int f[N][M];

//f[i][j][k]：收服前i个宠物时， 使用的精灵球数量不超过j，消耗的体力不超过k，捕捉的最大数量
//不捕捉第i个： f[i-1][j][k]
//捕捉第i个  ： f[i-1][j-v][k-m]+1;
//数组优化：倒序

int n, m, k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> k;
    for(int i = 1; i <= k; ++ i)
    {
        int v, t; cin >> v >> t;//球， 伤害
        
        for(int j = n; j >= v; -- j)
            for(int l = m - 1; l >= t; -- l)
                f[j][l] = max(f[j][l], f[j - v][l - t] + 1);
    }
    
    cout << f[n][m-1] << ' ';
    int cur = 0;
    while(cur < m && f[n][cur] != f[n][m-1]) ++ cur;
    cout << m - cur;
    
    
    return 0;
}


