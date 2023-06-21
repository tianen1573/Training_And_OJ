#include <iostream>
#include <cstring>

using namespace std;

int cnt[1011][33];
int n, m, t, p;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    cin >> t;
    for(int ii = 1; ii <= t; ++ ii)
    {
        cin >> m >> n >> p;
        int res = 0;
        
        for(int i = 1; i <= m; ++ i)
            for(int j = 1; j <= n; ++ j)
                cin >> cnt[i][j];
        
        for(int i = 1; i <= n; ++ i)
        {
            int cur = cnt[p][i];
            int maxx = -1;
            for(int j = 1; j <= m; ++ j)
                maxx = max(maxx, cnt[j][i]);
            
            res += maxx - cur;
        }
        
        printf("Case #%d: %d\n", ii, res);
    }
    
    return 0;
}