#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 111;

int f[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t; cin >> t;

    while(t --)
    {
        int r, c; cin >> r >> c;
        
        memset(f, 0, sizeof f);
        
        for(int i = 1; i <= r; ++ i)
            for(int j = 1; j <= c; ++ j) cin >> f[i][j];
            
        
        for(int i = 1; i <= r; ++ i)
            for(int j = 1; j <= c; ++ j)
                f[i][j] += max(f[i][j-1], f[i - 1][j]);
        
        cout << f[r][c] << endl;
    }
    
    
    return 0;
}