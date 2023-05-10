#include <cstdio>
#include <iostream>

#include <cstring>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 151110;

int h[N], ne[N], idx;//桶，next节点 -- 邻接表 稀疏图
PII ew[N];//值+权重
bool st[N];//确定集
int dist[N];//最短距离
priority_queue< PII, vector<PII>, greater<PII> > pque;//大堆_优先队列 距离——编号

int n, m;

void add(int a, int b, int w)
{
    ew[idx] = std::make_pair(b, w);
    ne[idx] = h[a];
    h[a] = idx;
    ++ idx;
}

void dijkstra()
{

    /*
    关于自环：非负自环，看着重边
    关于重边：通过a点更新其他点时，记为b点，会遍历a的邻接表，在遍历过程中，dist[b]会更新为最小值，根据堆的性质+定集， 可以确保，从取出的点是最小值，并且保证不重复取某个点
    */


    //0. 初始化
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    //1. 入队
    pque.push({0, 1});
    
    //堆优化 -- 根据朴素dijkstra算法， 每次选择的都是未确定的最短距离节点
    while(!pque.empty())
    {
        //2. 取未确定最小距离的点
        auto t = pque.top();//堆顶的节点，是未确定的且距离最短的节点
        pque.pop();
        
        int v = t.second;
        
        //一个节点只允许更新一次
        if(st[v]) continue;
        st[v] = true;
        
        
        //3. 更新其他点的距离
        for(int i = h[v]; ~i; i = ne[i])
        {
            // v 这一轮确定最短距离的点
            // i 与v连接的节点的在邻接链表中的索引值
            // e 与v连接的节点编号
            // w v->e 边的权值
            int e = ew[i].first;
            int w = ew[i].second;
            
            if(dist[e] > dist[v] + w)
            {
                dist[e] = dist[v] + w;
                
                //注意：堆优化时，无脑的将{距离-编号}放入了堆中
                //所以，堆中可能存在一个编号，多个距离的情况, 堆中存在大量的无用过期数据
                //则在取出某个节点时，将其放到定集中，避免多次更新 --- 定集：确定结果的集 -_-
                pque.push({dist[e], e});
                
            }
        }
        
    }
    
    if(dist[n] == 0x3f3f3f3f) cout << -1;
    else cout << dist[n];
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
        int a, b, w; cin >> a >> b >> w;
        add(a, b, w);
    }
    
    dijkstra();
    
    return 0;
}