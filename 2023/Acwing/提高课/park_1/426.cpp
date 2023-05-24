// 01背包

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 30010;

int f[N];

int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> m >> n;
    
    for(int i = 0; i < n; ++ i)
    {
        int v, p; cin >> v >> p;
        p *= v;
        
        for(int j = m; j >= v; -- j)
            f[j] = max(f[j], f[j - v] + p);
    }
    
    
    cout << f[m];
    
    return 0;
}
