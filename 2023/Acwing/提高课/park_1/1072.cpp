#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 10011, M = N << 1;

int h[N], e[M], w[M], ne[M], idx;
int res;

int n;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

int dfs(int u, int fat)
{
    int d1 = 0, d2 = 0;//子树 到 u 的 最大和次大 距离
    int dist = 0;//u为根节点的树 的 以u为 端点 的 最大距离
    
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(j == fat) continue; //子树的路径不允许经过父节点
        
        int d = dfs(j, u) + w[i];//子树j 到达 u 的 最大距离
        dist = max(dist, d);//更新u的最大距离
        
        //维护最大和次大
        if(d >= d1) d2 = d1, d1 = d;
        else if(d > d2) d2 = d;
        
    }
    
    res = max(res, d1 + d2);
    
    return dist;//返回u为根节点的树的最大距离
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    memset(h, - 1, sizeof h);
    
    cin >> n;
    for(int i = 1; i < n; ++ i)
    {
        int a, b, c; cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    
    dfs(1, -1);//随便指定一个根节点，往下递归
    
    cout << res << endl;
    
    return 0;
}
