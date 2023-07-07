#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 1011;

int g[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    int T; cin >> T;
    for(int t = 1; t <= T; ++ t)
    {
        int n; cin >> n;
        for(int i = 1; i <= n; ++ i)
            for(int j = 1; j <= n; ++ j)
                cin >> g[i][j];
        
        long long res = 0;
        long long last = 0;
        
        for(int col = 1; col <= n; ++ col)
        {
            last = 0;
            int x = 1, y = col;
            while(x <= n && y <= n)
            {
                last = max(last, (long long)0);
                last += g[x][y];
                res = max(res, last);
                
                x += 1, y += 1;
            }
        }
        for(int row = 2; row <= n; ++ row)
        {
            last = 0;
            int x = row, y = 1;
            while(x <= n && y <= n)
            {
                last = max(last, (long long)0);
                last += g[x][y];
                res = max(res, last);
                
                x += 1, y += 1;
            }
        }
        
        
        printf("Case #%d: %lld\n", t, res);
    }
    
    return 0;
}