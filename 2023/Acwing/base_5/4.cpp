#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1011;

int f[N][N];
int w[N], v[N], s[N];
int F[N];

int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i) cin >> v[i] >> w[i] >> s[i];
    
    //数据小 -- 暴力
    for(int i = 1; i <= n; ++ i)//1. 从第一个物品到第n个物品
        for(int j = 1; j <= m; ++ j)//2. 体积不超过j
            for(int k = 0; k * v[i] <= j && k <= s[i]; ++ k)//3. 状态转移第i个物品拿几个
                f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);
    
    
    cout << f[n][m];
    
    
    
    return 0;
}