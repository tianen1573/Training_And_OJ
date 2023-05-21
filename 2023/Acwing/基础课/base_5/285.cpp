#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 6010;

int h[N], e[N], ne[N], idx;

int happy[N];//每个节点的高兴值
int f[N][2];//以第i个节点为根的树， i参加或不参加时的树的happy总值
bool st[N];

int n;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int dfs(int u)
{
    //树是单向的，且能保证每个点仅遍历一次
    f[u][1] = happy[u];//初始化只有一个节点u参加时， 树的开心值，u也不参加时，则为0
    
    //遍历子节点
    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        
        dfs(j);//从下到上
        
        f[u][1] += f[j][0];//u节点参加时，其子节点必不能参加
        f[u][0] += max(f[j][0], f[j][1]);//u节点没参加时，子节点参不参加都可以
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    memset(h, -1, sizeof h);
    
    cin >> n;
    for(int i = 1; i <= n; ++ i)
    {
        cin >> happy[i];
    }
    for(int i = 0; i < n - 1; ++ i)
    {
        int a, b; cin >> a >> b;
        st[a] = true;
        add(b, a);
    }
    
    //求根节点
    int root = 1;
    while(st[root]) ++ root;
    
    dfs(root);
    
    cout << max(f[root][0], f[root][1]);
    
    return 0;
}