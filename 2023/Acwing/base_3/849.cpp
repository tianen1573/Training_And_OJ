#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;



const int N = 510;

int g[N][N];//邻接矩阵 ----  稠密图
bool st[N];//状态数组
int dist[N];//最短距离数组

int n, m;


void dijkstra()
{
    //0. 初始化最短距离
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    //n次遍历 -- 每次都确定一个最短距离
    for(int i = 0; i < n; ++ i)
    {
        //1. 找未确定最短距离的点
        int t = -1;//是连接点的编号，不是距离
        for(int j = 1; j <= n; ++ j)
        {
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        }
        
        //2. 确认该点， 放到集合里
        st[t] = true;
        
        //3. 通过这个点更新到其他点的最短距离
        for(int j = 1; j <= n; ++ j)
        {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    
    
    if(dist[n] == 0x3f3f3f3f) cout << -1;
    else cout << dist[n];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    
    memset(g, 0x3f, sizeof g);
    // for(int i = 1; i <= n; ++ i) g[i][i] = 0;//避免自环
    
    cin >> n >> m;
    while(m -- )
    {
        int a, b, w; cin >> a >> b >> w;
        
        g[a][b] = min(g[a][b], w);//存在重复边，保存权值最小的那一个
    }
    
    dijkstra();
    
    return 0;
}