//LCA

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 100011;
typedef long long LL;


vector<pair<int, int>> g[N];
LL f[N][30], dist[N];
int dep[N];

int n, k;


void dfs(int u, int fa, LL distance)
{
    dep[u] = dep[fa] + 1, dist[u] = distance, f[u][0] = fa;

    for (int i = 1; (1 << i) <= dep[u]; ++ i) 
        f[u][i] = f[f[u][i - 1]][i - 1];

    //dfs
    for(auto &t : g[u])
    {
        int j = t.first;
        if(j == fa) continue;

        dfs(j, u, distance + t.second);
    }
}

int lca(int a, int b)
{
    if(dep[a] < dep[b]) swap(a, b);

    for(int i = 20; i >= 0; -- i)
    {
        if(dep[f[a][i]] >= dep[b]) a = f[a][i];
        if(a == b) return a;
    }

    for(int i = 20; i >= 0; -- i)
    {
        //不相等，则两点都可以往上爬
        //相等时，不一定是  *最近* 公共父节点
        if(f[a][i] != f[b][i])
        {
            a = f[a][i];
            b = f[b][i];
        }
    }

    return f[a][0];
}

LL getdist(int a, int b)
{
    return dist[a] + dist[b] - 2 * dist[lca(a, b)];
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    cin >> n >> k;
    for(int i = 1; i < n; ++ i)
    {
        int a, b, w; cin >> a >> b >> w;
        g[a].push_back({b, w}), g[b].push_back({a, w});
    }
    dfs(1, 0, 0);

    vector<int> away(k + 1);
    for(int i = 1; i <= k; ++ i)
        cin >> away[i];
    
    LL sum = 0;
    for(int i = 1; i < k; ++ i) sum += getdist(away[i], away[i + 1]);

    for(int i = 1; i <= k; ++ i)
    {
        LL ans = sum;
        if(i != 1) ans -= getdist(away[i - 1], away[i]);
        if(i != k) ans -= getdist(away[i], away[i + 1]);
        if(i != 1 && i != k) ans += getdist(away[i - 1], away[i + 1]);
    
        cout << ans << ' ';
    }

    return 0;
}