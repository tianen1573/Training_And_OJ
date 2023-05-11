#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 10010;

int h[N], e[N], w[N], ne[N], idx;//邻接表
int dist[N], cnt[N];//最短距离，经过边数
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

bool spfa()
{
    /*自己实现的队列，如果不是循环数组实现的，不再适合
    * 为什么?
    * spfa的工作原理是，当变化队列里不存在距离更新的点时，则代表此时1到其他点的所有距离一定是最短的
    * 但若图中存在负权回路，在一直会存在更新的点，队列不可能为空(爆数据不考虑)
    * 所以我们自己实现的队列，必须是循环数组实现队列，不然会爆空间
    * 因为负权回路不一定存在1到n这条路径上，所以我们需要把所有的节点都预先放到队列中
    * 即使一个节点和1不连接，但由于我们设置的不连接时最短距离为0x3f3f3f3f，是逻辑上的不连接
    * 则存在负权回路时，其中一条边(a,b,c:c<0)+(b,a,c:c<0),1到a到b的距离都是0x3f3f3f3f
    * 我们可以通过这个负权回路，无限更新ab的最短距离，直至负无穷
    * 在这个过程中，记录节点此时经过的边数，超过n-1，则肯定存在负权回路
    */
    queue<int> que;
    //0. 初始化距离数组和变化队列
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for(int i = 1; i <= n; ++ i)
    {
        st[i] = true;
        que.push(i);
    }
    
    
    while(que.size())
    {
        //1. 取出一个变化的点更新其他点 ---- (a, b, w)
        int cur = que.front();//a
        que.pop();
        st[cur] = false;//代表cur编号可再次入队
        
        //2. 更新其他点
        for(int i = h[cur]; i != -1; i = ne[i])
        {
            int ver = e[i], distance = w[i];//b, w
            
            //通过a的周转， b的最短距离变化了
            if(dist[ver] > dist[cur] + distance)
            {
                dist[ver] = dist[cur] + distance;
                cnt[ver] = cnt[cur] + 1;
                if(cnt[ver] >= n) return true;//(1->n, 路径上无负环至多经过n-1个点)
                //任一时刻，只允许一个b节点在队列中
                //我们在队列中存储的是节点编号，所有相同的编号共享一个数据
                //则在一个节点在队列时，其最短距离更新了，这个队列里的节点是能够知道的
                //不需要额外添加到队列中， 减少入队次数
                
                if(!st[ver])
                {
                    st[ver] = true;
                    que.push(ver);
                }
            }
            
        }
    }
    
    return false;
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
    
    
    if(spfa()) cout << "Yes";
    else cout << "No";
    
    return 0;
}