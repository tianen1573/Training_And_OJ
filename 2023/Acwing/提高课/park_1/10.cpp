//f[i][j]：以i为根节点的树，且选上i，并且体积不超过j 的 最大值
// https://www.acwing.com/solution/content/54139/
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 111;

int h[N], e[N], ne[N], idx = 1;
int v[N], w[N];

int f[N][N];

int n, m;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a]  = idx ++ ;
}

void dp(int u)
{
    for(int i = h[u]; ~i; i = ne[i])//枚举子树 -- 顺序枚举，选或不选
    {
        int t = e[i];
        dp(t);//先算子节点的状态
        
        //u是必选的节点， 所以j从 m - v[u] 开始
        for(int j = m - v[u]; j >= 0; -- j)//枚举根节点所在树的空间(去掉了v[u]，保证能够放进去物品u)
            for(int k = 0; k <= j; ++ k)//枚举分配给子树的空间， 子树的空间不能大于
                f[u][j] = max(f[u][j], f[u][j - k] + f[t][k]);
                //f[u][j]: u为根节点的树，选上u不超过j， j = 0 时代表不选u
                //f[u][j - k]: u为根节点的树， 选上u不超过j-k
                //f[t][k]: t为根节点的树，选上t不超过k， k = 0 时代表不选t
        
    }
    
    //u必须选
    for(int j = m; j >= v[u]; -- j) f[u][j] = f[u][j - v[u]] + w[u];
    for(int j = 0; j < v[u]; ++ j) f[u][j] = 0;//体积不够
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    memset(h, -1, sizeof h);
    int root = 0;
    
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i)
    {
        int p;
        cin >> v[i] >> w[i] >> p;
        
        if(p == -1) root = i;
        else add(p, i);
    }
    
    dp(root);
    
    cout << f[root][m];
    
    return 0;
}
