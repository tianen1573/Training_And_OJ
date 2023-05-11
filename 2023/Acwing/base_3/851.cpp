//bellman_man可以选择最大经过边数， 每次遍历都需要遍历所有的边，所以我们只需要保存边的信息即可，不需要构建点的邻接表
//而spfa是队列优化版本：只有当一个节点被更新时，通过这个节点周转时，其他节点才会更新，则我们需要构建邻接表
//因为spfa是根据，最短距离变化跟新节点的，则1->n若存在负权回路，加上spfa不能指定最大变数， 则会一直存在最短距离更新的点
//即负权回路上的点的最短距离会一直变小，死循环，则spfa不能解决存在负权回路的最短路径问题，但可以解决正权回路

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;

int h[N], e[N], w[N], ne[N], idx;
int heap[N * 2], hh = 0, tt = -1;
int dist[N];
bool st[N];

int n, m;

void add(int a, int b, int d)
{
    e[idx] = b;
    w[idx] = d;
    ne[idx] = h[a];
    h[a] = idx;
    ++ idx;
}

int spfa()
{
    //0. 初始化距离数组和变化队列
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    heap[++ tt] = 1;
    st[1] = true;
    
    while(hh <= tt)
    {
        //1. 取出一个变化的点更新其他点 ---- (a, b, w)
        int cur = heap[hh ++];//a
        st[cur] = false;//代表cur编号可再次入队

        //2. 更新其他点
        for(int i = h[cur]; i != -1; i = ne[i])
        {
            int ver = e[i], distance = w[i];//b, w
            
            //通过a的周转， b的最短距离变化了
            if(dist[ver] > dist[cur] + distance)
            {
                dist[ver] = dist[cur] + distance;
                //任一时刻，只允许一个b节点在队列中
                //我们在队列中存储的是节点编号，所有相同的编号共享一个数据
                //则在一个节点在队列时，其最短距离更新了，这个队列里的节点是能够知道的
                //不需要额外添加到队列中， 减少入队次数
                if(!st[ver])
                {
                    st[ver] = true;
                    heap[++ tt] = ver;
                }
            }
            
        }
    }
    
    return dist[n];
}



int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    memset(h, -1, sizeof h);
    
    cin >> n >> m;
    while(m --)
    {
        int a, b, c; cin >> a >> b >> c;
        
        add(a, b, c);
    }
    
    int ret = spfa();
    if(ret > 0x3f3f3f3f / 2) cout << "impossible";
    else cout << ret; 
    
    return 0;
}