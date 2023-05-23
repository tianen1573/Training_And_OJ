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