#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 111, M = N << 1;

int h[N], e[M], w[M], ne[M], idx;

int f[N][N];//f[i][j],以i为根节点的树， 保留的苹果（树枝）数量为j 的 最小剪枝数

int n, m;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
void dfs(int u, int father)
{
    for(int i = h[u]; ~i; i = ne[i])
    {
        if(father == e[i]) continue;
        
        dfs(e[i], u);
        
        //分组背包：按体积(树枝)决策
        for(int j = m; j >= 1; -- j)
            for(int k = 0; k + 1 <= j; ++ k)
                f[u][j] = max(f[u][j], f[u][j - k - 1] + f[e[i]][k] + w[i]);
    }
}

int main()
{
    memset(h, -1, sizeof h);
    
    cin >> n >> m;
    for(int i = 1; i < n; ++ i)
    {
        int a, b, c;
        cin >> a >>b >>c;
        
        add(a, b, c), add(b, a, c);
    }
    
    dfs(1, -1);
    
    cout << f[1][m];
    
    return 0;
}