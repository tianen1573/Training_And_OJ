#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 2e5 + 11;

int h[N], e[N << 1], ne[N << 1], idx;
int cnt[N], w[N];
bool st[N];
int res;

int t, n;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u)
{
    //u只能递归比他小的子树
    st[u] = true;
    int count = 1;
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        
        if(w[u] <= w[j]) continue;
        if(!st[j]) dfs(j);
        
        count += cnt[j];
        
    }
    res = max(res, count);
    cnt[u] = count;
}

int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    
    cin >> t;
    for(int ii = 1; ii <= t; ++ ii)
    {
        memset(h, -1, sizeof h);
        memset(cnt, 0, sizeof cnt);
        memset(st, 0, sizeof st);
        res = 1, idx = 0;
        
        cin >> n;
        for(int i = 1; i <= n; ++ i) 
        {
            cin >> w[i];
        }
        for(int i = 1; i < n; ++ i)
        {
            int a, b; cin >> a >> b;
            add(a, b), add(b, a);
        }
        
        for(int i = 1; i <= n; ++ i)
            if(!st[i]) dfs(i);
        
        // for(int i = 1; i <= n; ++ i)
        //     cout << cnt[i] << ' ';
        // cout << endl;
        
        printf("Case #%d: %d\n", ii, res);
    }
    
    return 0;
}