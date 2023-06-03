#include <iostream>
#include <cstring>

using namespace std;

const int N = 2 * 1e6 + 11;

int oil[N], dist[N];
long long s[N];
int que[N], hh = 0, tt = -1;
bool st[N];

int n;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++ i)
    {
        cin >> oil[i] >> dist[i];
    }
    
    //顺时针 1->2->3->4->1->2->3->4
    //oil[i] - dist[i]：代表 i点到i+1点 油量
    for(int i = 1; i <= n; ++ i) s[i] = s[i + n] = oil[i] - dist[i];
    for(int i = 1; i <= 2*n; ++ i) s[i] += s[i - 1];
    hh = 0, tt = -1;
    for(int i = 2*n; i >= 1; -- i)//后序，i固定，求滑动窗口最小值
    {
        while(hh <= tt && que[hh] - n + 1 > i) ++ hh;//区间最多为n
        while(hh <= tt && s[i] <= s[que[tt]]) -- tt;
        que[++ tt] = i;
        
        //后续遍历， i<=n，代表够一圈了
        //此时长度为n的窗口的最小值，比当前加油站-1的前缀和大于等于
        //代表从该加油站顺时针出发，可以走一圈
        if(i <= n && s[que[hh]] - s[i - 1] >= 0) st[i] = true;
    }
    
    //逆时针 (4)0<-1<-2<-3<-4<-1<-2<-3<-4
    ///oil[i] - dist[i - 1]：代表 i点到i-1点 油量
    dist[0] = dist[n];//更新0<-1的距离
    for(int i = 1; i <= n; ++ i) s[i] = s[i + n] = oil[i] - dist[i - 1];
    for(int i = 2*n; i >= 1; -- i) s[i] += s[i+1];
    hh = 0, tt = -1;
    for(int i = 1; i <= 2*n; ++ i)//前序，i固定，求滑动窗口最小值
    {
        while(hh <= tt && i - que[hh] + 1 > n) ++ hh;
        while(hh <= tt && s[i] <= s[que[tt]]) -- tt;
        que[++ tt] = i;
        
        if(i >= n + 1 && s[que[hh]] - s[i + 1] >= 0) st[i - n] = true;
    }
    
    for(int i = 1; i <= n; ++ i)
        if(st[i]) cout << "TAK" << endl;
        else cout << "NIE" << endl;
    
    return 0;
}