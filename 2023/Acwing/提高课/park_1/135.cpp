#include <iostream>
#include <cstring>

using namespace std;

const int N = 300011;

typedef long long LL;

LL sum[N];
// int f[N];//以i结尾的，长度不超过m的最大字串和
LL que[N];
int hh = 0, tt = -1;

int n, m;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i)
    {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }
    
    
    LL res = -(1e18 + 11);
    //预先把sum[0],放入队列中
    que[++ tt] = 0;
    for(int i = 1; i <= n; ++ i)
    {
        //此时我们存储的是前缀和数组的下标，我们要维护的窗口大小为m
        //对于原数组[a, b], b - a + 1 <= m
        //转换成前缀和数组，b - a <= m 
        while(hh <= tt && i - que[hh] > m) ++ hh;
        while(hh <= tt && sum[i] <= sum[que[tt]]) -- tt;
        res = max(res, sum[i] - sum[que[hh]]);//que存储的是窗口左端点-1的的前缀和
        que[++ tt] = i;
    }
    
    cout << res;
    
    return 0;
}