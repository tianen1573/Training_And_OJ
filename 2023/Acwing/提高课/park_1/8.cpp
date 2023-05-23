#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1010, M = 110;

int f[M][M]; // 取前i个， 且体积不超过j，重量不超过k 的 最大价值
//f[i][j][k]: 不选第i个, 则 f[i - 1][j][k];
//              选，     则 f[i-1][j-v][k-m] + w

int n, v, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> v >> m;
    
    for(int i = 1; i <= n; ++ i)
    {
        int a, b, c; cin >> a >> b >> c;
        
        for(int j = v; j >= a; -- j)
            for(int k = m; k >= b; -- k)
                f[j][k] = max(f[j][k], f[j - a][k - b] + c);
    }
    
    cout << f[v][m];
    
    return 0;
}