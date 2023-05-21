#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100010;

int h[N], e[N*2], ne[N*2], idx;//除了e数组，下标都代表索引
int d[N];//下标代表数值
bool st[N];//下标代表数值

int q[N], hh = 0, tt = -1;

int n, m;

void add(int k, int val)
{
    //去重边
    for(int i = h[k]; i != -1; i = ne[i])
        if(e[i] == val) return ;
    
    d[val] ++;//入度加1
    e[idx] = val;
    ne[idx] = h[k];
    h[k] = idx;
    ++ idx;
}

void bfs()
{
    while(hh <= tt)
    {
        int cur = q[hh ++];
        
        for(int i = h[cur]; i != -1; i = ne[i])
        {
            //已经入队
            if(st[e[i]]) continue;
            
            //入度减一
            d[e[i]] --;
            if(d[e[i]] == 0)//为0，可入队
            {
                st[e[i]] = true;
                q[++ tt] = e[i];
            }
        }
    }
    
    //如果存在自环， 则一定不会存在n个处理后入度为0的节点
    if(tt + 1 == n)
        for(int i = 0; i < n; ++ i)
            cout << q[i] << ' ';
    else
        cout << -1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    memset(h, -1, sizeof h);
    
    cin >> n >> m;
    while(m --) 
    {
        int a, b; cin >> a >> b;
        
        add(a, b);
    }
    for(int i = 1; i <= n; ++ i)
    {
        // cout << i << ':' << d[i] << endl;
        if(d[i] == 0)
        {
            q[++ tt] = i;
            st[i] = true;
        }
    }
    bfs();
    
    return 0;
}