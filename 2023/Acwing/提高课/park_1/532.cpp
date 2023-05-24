//解析： https://www.acwing.com/solution/content/53198/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int M = 25010, N = 110;

int h[N], f[M];

int n, m, t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> t;
    
    while(t --)
    {
        cin >> n;
        for(int i = 1; i <= n; ++ i) cin >> h[i];
        sort(h + 1, h + 1 + n);
        m = h[n];
        
        
        int res = 0;
        memset(f, 0, sizeof f);//共用的
        f[0] = 1;
        for(int i = 1; i <= n; ++ i)
        {
            
            if(f[h[i]]) continue;
            
            //方案数为0， 代表前面的元素，无法构成该值
            //bool数组更好
            res ++;
            for(int j = h[i]; j <= m; ++ j)
                f[j] += f[j - h[i]];
        }
        
        cout << res << endl;
        
    }
    
    
    return 0;
}
