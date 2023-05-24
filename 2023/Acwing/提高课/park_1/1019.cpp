#include <cstdio>
#include <iostream>

using namespace std;

const int N = 510, M = 6010;

// int f[N][M]; //从前i个选， 体积不超过j 的 最大价值
int f[M];

int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; ++ i)
    {
        int v, w, s; cin >> v >> w >> s;
        
        //优化数组
        for(int j = m; j >= v; -- j)
            for(int k = 0; k * v <= j && k <= s; ++ k)
                f[j] = max(f[j], f[j - k * v] + k * w);
    }
    
    cout << f[m];
    
    
    return 0;
}



#include <cstdio>
#include <iostream>

using namespace std;

const int N = 510 * 4, M = 6010;

//二进制优化为01背包问题
// int f[N][M]; //从前i个选， 体积不超过j 的 最大价值
int f[M];
int V[N], W[N], S[N];

int n, m, cnt;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; ++ i)
    {
        int v, w, s; cin >> v >> w >> s;
        
        int k = 1;
        while(k <= s)
        {
            V[++ cnt] = k * v;
            W[cnt] = k * w;
            
            s -= k;
            k *= 2;
        }
        
        if(s)
        {
            V[++ cnt] = s * v;
            W[cnt] = s * w;
        }
    }
    n = cnt;
    
    for(int i = 1; i <= n; ++ i)
    {
        for(int j = m; j >= V[i]; -- j)
            f[j] = max(f[j], f[j - V[i]] + W[i]);
    }
    
    cout << f[m];
    
    
    return 0;
}