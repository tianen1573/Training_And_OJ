#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010;

int v[N], w[N];
int f[N][N];
int way[N];

int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i) cin >> v[i] >> w[i];
    
    for(int i = n; i >= 1; -- i)
        for(int j = 0; j <= m; ++ j)
        {
            f[i][j] = f[i + 1][j];
            if(j >= v[i]) f[i][j] = max(f[i][j], f[i + 1][j - v[i]] + w[i]);
        }
    
    //反序dp，则f[1][m]为最大价值
    //那么选择物品时， 若该物品满足条件，则一定要选，满足字典序最小
    
    int vol = m;
    for(int i = 1; i <= n; ++ i)
        if(vol >= v[i] && f[i][vol] == f[i + 1][vol - v[i]] + w[i])
        {
            cout << i << ' ';
            
            vol -= v[i];
        }
    
    return 0;
}
