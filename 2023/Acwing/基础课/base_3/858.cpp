#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 511;
const int INF = 0x3f3f3f3f;

int g[N][N];
int dist[N];
bool st[N];

int n, m;

int prim()
{
    //0.初始化
    memset(dist, 0x3f3f3f, sizeof dist);
    dist[1] = 0;//有无都可
    
    //集合边权和
    int res = 0;
    
    //n次循环
    for(int i = 0; i < n; ++ i)
    {
        //1. 找不在集合里，距离集合最近的点
        /*
        * 下面的代码中，当集合为空时，即i==0时，权重和并没有加上当前节点与集合的距离的
        * 下面的代码，也能保证，第一次遍历时，从节点1开始，并且第一个节点距离集合的距离不会计算，所以dist[1]初不初始化无所谓
        */
        int t = -1;
        for(int j = 1; j <= n; ++ j)
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        
        
        //集合不为空，但未在集合的点与集合的最小距离是INF，则剩下的节点都与集合不连接，
        //代表不存在最小生成树
        if(i && dist[t] == INF) return INF;
        
        //2. 放入集合 更新权重和
        if(i) res += dist[t];//集合不为空，集合的边的权重，这里舍弃掉了第一个节点
        st[t] = true;//将该点放到集合中
        
        
        //3. 更新其他点到集合的距离
        //相较于dijkstra算法，通过t点，更新其他不在集合的点到节点1的距离
        //prim，通过t点，更新的是其他不在集合的点，到集合的距离
        for(int j = 1; j <= n; ++ j) dist[j] = min(dist[j], g[t][j]);
    }
    
    
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    
    memset(g, 0x3f, sizeof g);
    
    while( m --)
    {
        int a, b, c; cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    
    
    int ret = prim();
    
    if(ret == INF) cout << "impossible\n";
    else cout << ret;
    
    return 0;
}