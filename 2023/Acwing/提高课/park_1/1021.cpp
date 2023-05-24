//完全背包

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int M = 3010;

long long f[M];

int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    f[0] = 1;
    for(int i = 1; i <= n; ++ i)
    {
        int v; cin >> v;
        
        for(int j = v; j <= m; ++ j)
            f[j] += f[j - v];
    }
    
    cout << f[m];
    
    return 0;
}