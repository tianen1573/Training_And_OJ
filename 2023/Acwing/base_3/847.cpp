#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 100010;

//h存储连通节点的索引， e存储值， ne存储next节点
int h[N], e[N*2], ne[N*2], idx;
int que[N*2], hh = 0, tt = -1;
bool st[N];

int n, m;

void add(int k, int val)
{
    e[idx] = val;
    ne[idx] = h[k];
    h[k] = idx;
    ++ idx;
}

//只有que和e数组存储的是数值，st下标代表数值，而其他的代表索引
int bfs()
{
    que[++ tt] = 1;
    st[1] = true;
    
    int res = 0;
    while(hh <= tt)
    {
        int ttt = tt;
        
        while(hh <= ttt)
        {
            int cur = que[hh ++];
            if(cur == n) return res;
            
            for(int i = h[cur]; i != -1; i = ne[i])
            {
                if(st[e[i]]) continue;
                
                que[++ tt] = e[i];
                st[e[i]] = true;
            }
        }
        ++ res;
    }
    
    return -1;//走到这里代表没找打
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(nullptr);
    
    memset(h, -1, sizeof h);
    
    cin >> n >> m;
    
    for(int i = 0; i < m; ++ i)
    {
        int a, b; cin >> a >> b;
        add(a, b);
    }
    
    cout << bfs();
    
    return 0;
}