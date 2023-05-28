//f[i][2]: 走到第i家店时， 偷 或 不偷 时 的 最大价值
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 11;

int f[2][2];//滚动数组优化

int t, n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> t;
    while(t -- )
    {
        cin >> n;
        
        memset(f, 0, sizeof f);
        
        for(int i = 1; i <= n; ++ i)
        {
            int val; cin >> val;
            
            f[i & 1][0] = max(f[i - 1 & 1][0], f[i - 1 & 1][1]);
            f[i & 1][1] = f[i - 1 & 1][0] + val;
        }
        
        cout << max(f[n & 1][0], f[n & 1][1]) << endl;
    }
    
    
    return 0;
}

