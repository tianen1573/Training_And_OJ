#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 1511;

int h[N], e[N], w[N], ne[N], idx;
int st[N];

int f[N][3];//看md

int n;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u)
{
    f[u][2] = w[u];
    int sum = 0;
    
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        dfs(j);
        
        f[u][0] += min(f[j][1], f[j][2]);
        f[u][2] += min(min(f[j][1], f[j][2]), f[j][0]);
        
        sum += min(f[j][1], f[j][2]);
    }
    
    
    f[u][1] = 1e9;
    //求f[u][1]被哪一个子节点看到的
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        //去掉预处理 加上的 j节点的值， 加上 应该加上的 j节点的值
        f[u][1] = min(f[u][1], sum - min(f[j][1], f[j][2]) + f[j][2]);
    }
}


int main()
{
    memset(h, -1, sizeof h);
    
    cin >> n;
    for(int i = 1; i <= n; ++ i)
    {
        int pre, val, cnt;
        cin >> pre >> val >> cnt;
        w[pre] = val;
        while(cnt -- )
        {
            int son;
            cin >> son;
            add(pre, son);
            st[son] = true;
        }
    }
    
    int root = 1;
    while(st[root]) ++ root;
    
    dfs(root);
    
    //根节点不存在父节点
    cout <<min(f[root][1], f[root][2]) << endl;
    
    
    return 0;
}