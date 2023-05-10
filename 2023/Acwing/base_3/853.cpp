// n * m

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;


//保存所有边
struct str{
    int a, b, w;
}edgs[N];

int n, m, k;
int dist[N], backup[N];//最短距离数组， 备份数组

void bellman_ford()
{
    //复杂的 ： k * m ，k：最大可经过边数， m所有的边数
    //如果存在环路， k可以大于 n
    //如果存在负权回路，且在1->n的路径上， k大于n时， 多转几圈比较好
    
    
    /*
    关于重边：因为ford算法，会把所有边都遍历一遍，则会自己选择最小权值的那一条边
    关于自环：对于[a->a, w = 0]， 可理解为多了个重边[a->a, w = w]
    算法会在遍历时，选择最好的边
    */
    
    //0. 初始化
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    //1. k次循环， 即1到n可经过的最大
    for(int i = 0; i < k; ++ i)
    {
        //2. 备份数组， 保证更新时，轮次相等
        memcpy(backup, dist, sizeof dist);
        
        for(int j = 1; j <= m; ++ j)
        {
            auto e = edgs[j];// a->b, w
            //为什么需要一个备份的backup数组
            //因为ford算法，是 需要 遍历所有的边 来 更新1到其他点的距离的
            //那么在一次遍历过程中， 可能会对一个点更新多次，如果我们直接使用dist数组计算距离
            //有可能，在第j轮， a->b, w ： 我们从a更新b时， a是本轮经过更新的值
            //dist[a] 是经过i次更新过的值， 我们用它跟新dist[b], 则dist[b] 变成了i+1轮
            //不符合要求， 所以我们需要把上一轮更新的值，保存下来， 保证所有节点在更新时， 都在同一轮次
            dist[e.b] = min(dist[e.b], backup[e.a] + e.w);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    cin >> n >> m >> k;
    for(int i = 1; i <= m; ++ i)
    {
        int a, b, c; cin >> a >> b >> c;
        edgs[i] = {a, b, c};
    }
    
    bellman_ford();
    
    if(dist[n] > 0x3f3f3f3f / 2) cout << "impossible";
    else cout << dist[n];
    
    return 0;
}