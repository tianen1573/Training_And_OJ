#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010, MOD =  1e9 + 7;

int f[N], g[N];

int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    // for(int i = 0; i <= n; ++ i) g[0][i] = 1;
    g[0] = 1;
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; ++ i)
    {
        int v, w; cin >> v >> w;
        
        for(int j = m; j >= v; -- j)
            if(f[j - v] + w < f[j]) continue;
            else if(f[j - v] + w == f[j]) g[j] = (g[j] + g[j - v]) % MOD;
            else f[j] = f[j - v] + w, g[j] = g[j - v];
    }
    
    int res = 0;
    for(int i = 0; i <= m; ++ i)
        if(f[i] == f[m])
            res = (res + g[i]) % MOD;
            
    cout << res;
    
    return 0;
}
