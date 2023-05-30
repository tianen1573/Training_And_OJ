
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 11;

int f[N][3];

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    f[0][0] = -0x3f3f3f3f;
    cin >> n;
    
    for(int i = 1; i <= n; ++ i)
    {
        int val; cin >> val;
        
        f[i][0] = max(f[i-1][0], f[i-1][2] - val);
        f[i][1] = f[i - 1][0] + val;
        f[i][2] = max(f[i - 1][1], f[i - 1][2]);
    }
    
    
    cout << max(f[n][1],f[n][2]);
    
    return 0;
}
