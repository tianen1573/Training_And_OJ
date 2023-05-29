//变环为链
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 413;

int f[N][N];
int g[N][N];

int w[N];
int s[N];

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; ++ i)
    {
        cin >> w[i];
        w[i + n] = w[i];
    }
    for(int i = 1; i <= 2*n; ++ i) s[i] = s[i - 1] + w[i];
    
    memset(f, -0x3f, sizeof f);//maxv
    memset(g, 0x3f, sizeof g);//minv
    for(int i = 1; i <= 2 * n; ++ i) f[i][i] = g[i][i] = 0;//一个石子时，合并代价为0
    
    for(int len = 2; len <= n; ++ len)//至少 2个节点 到 至多n个节点
        for(int i = 1; i + len - 1 <= 2 * n; ++ i)
        {
            int l = i, r = i + len - 1;
            int sum = s[r] - s[l - 1];
            
            
            for(int k = l; k < r; ++ k)
            {
                f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r] + sum);
                g[l][r] = min(g[l][r], g[l][k] + g[k + 1][r] + sum);
            }
        }
    
    int maxv = -0x3f3f3f3f, minv = 0x3f3f3f3f;
    for(int i = 1; i <= n; ++ i)// i 到 i + n - 1 成链
    {
        maxv = max(maxv, f[i][i + n - 1]);
        minv = min(minv, g[i][i + n - 1]);
    }
    
    cout << minv << endl << maxv;
    
    return 0;
}
