#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1010;

int f[N];

int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    
    cin >> m >> n;
    for(int i = 1; i <= n; ++ i)
    {
        int v, w; cin >> v >> w;
        
        for(int j = m; j >= v; -- j)
            f[j] = max(f[j], f[j - v] + w);
    }
    
    cout << f[m];
    
    return 0;
}