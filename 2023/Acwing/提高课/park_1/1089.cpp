#include <iostream>
#include <cstring>

using namespace std;

const int N = 2e5 + 11;

int h[N];
int f[N];//以i为右端点，且选择i的 最小代价方案
int que[N], hh = 0, tt = -1;

int n, m;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i) cin >> h[i];
    
    tt = 0;//前m个，可以只点亮一个
    for(int i = 1; i <= n; ++ i)
    {
        //i是点燃的，则可以从i之前的m个转移
        while(hh <= tt && i - m > que[hh]) ++ hh;
        f[i] = f[que[hh]] + h[i];//这里的f[i]不能由自身转移而来，所以先转移再入队
        while(hh <= tt && f[que[tt]] >= f[i]) -- tt;
        que[++ tt] = i;
    }
    
    int res = 1e9 + 11;
    
    //取最后m个烽火台点燃的最小代价
    for(int i = n - m + 1; i <= n; ++ i) res = min(res, f[i]);
    cout << res;
    
    return 0;
}