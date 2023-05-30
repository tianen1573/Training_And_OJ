#include <iostream>
#include <cstring>

using namespace std;

const int N = 50011;

int h[N], e[N], ne[N], idx;

int sum[N];
int d1[N], d2[N];
int res;

int n;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int u)
{
    if(d1[u]) return;//因为外部多次dfs，所以若d1[u] != 0, 代表已经dfs过
    
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        dfs(j);
        //j的最大和次大距离，保存在数组中了
        if(d1[j] + 1 >= d1[u]) d2[u] = d1[u], d1[u] = d1[j] + 1;
        else if(d1[j] + 1 > d2[u]) d2[u] = d1[j] + 1;
    }
    
    res = max(res, d1[u] + d2[u]);
}

int main()
{
    memset(h, -1, sizeof h);
    
    cin >> n;
    
    for(int i = 1; i <= n; ++ i)
        for(int j = 2; j <= n / i; ++ j)//i * j <= n, 只要这个式子成立， 就把i*j的因数i加上
            sum[i * j] += i;
            
    for(int i = 2; i <= n; ++ i)
        if(sum[i] < i)//约数和 小于 自身
            add(sum[i], i);
    
    for(int i = 1; i <= n; ++ i) dfs(i);//可能存在连通块
    
    cout << res;
    
    return 0;
}