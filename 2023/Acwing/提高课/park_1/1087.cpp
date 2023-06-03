#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 11;

int que[N], hh = 0, tt = -1;
long long f[N], sum;

int n, m;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i)
    {
        cin >> f[i];
        sum += f[i];
    }
    
    tt = 0;
    for(int i = 1; i <= n; ++ i)
    {
        while(hh <= tt && i - m - 1 > que[hh]) ++ hh;
        f[i] += f[que[hh]];
        while(hh <= tt && f[que[tt]] >= f[i]) -- tt;
        que[++ tt] = i;
    }
    
    long long res = 1e18 + 11;
    for(int i = n - m; i <= n; ++ i)
        res = min(res, f[i]);
    cout << sum - res;
    
    return 0;
}