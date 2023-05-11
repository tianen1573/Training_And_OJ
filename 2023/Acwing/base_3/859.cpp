#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;
const int INF = 0x3f3f3f3f;

int p[N];
struct Edge{
    int a, b, w;
    
    bool operator< (const Edge& e) const
    {
        return w < e.w;
    }
    
}edges[N*2];

int n, m;


int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    
    return p[x];
}

/*
* kruskals算法结合了并查集思想
* 我们把所有的节点预先切割成单节点连通块，如果这些连通块可以连接成一个连通块
* 当两个连通块相连时我们记录一次，则遍历完提供的边时，cnt == n - 1
* 若cnt没有到达n-1，则该图一定存在2个及以上的连通块，无法生成树
* 关于如何证明 对边排序后遍历，使得树的边权重和为最小，我母鸡。
*/
int kruskal()
{
    //0. 初始化并查集，和对边排序
    for(int i = 1; i <= n; ++ i) p[i] = i;
    sort(edges, edges + m);
    
    //1. 初始化权重和，和变数
    int res = 0, cnt = 0;
    for(int i = 0; i < m; ++ i)
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        
        //2. 判断是否在一个连通块
        a = find(a), b = find(b);
        
        //3. 不在， 连接成一个块
        if(a != b)
        {
            res += w;//更新和
            p[a] = b;//连接
            cnt ++ ;//记录边
        }
    }
    
    
    //4. 判断
    if(cnt < n - 1) return INF;
    else return res;
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; ++ i)
    {
        int a,b,w; cin >> a >> b >> w;
        
        edges[i] = {a,b,w};
    }
    
    int t = kruskal();
    
    if (t == INF)cout << "impossible";
    else cout << t;
    
    
    return 0;
}