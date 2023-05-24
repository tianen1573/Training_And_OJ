#include <cstdio>
#include <iostream>

using namespace std;

const int N = 17;

int f[N][N];
int w[N][N];
int way[N];

int n, m;

int main()
{
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            cin >> w[i][j];
    
    for(int i = 1; i <= n; ++ i)//先枚举物品种类
        for(int j = 0; j <= m; ++ j)//再枚举空间
            for(int k = 0; k <= j; ++ k)//最后枚举i类物品
                    f[i][j] = max(f[i][j], f[i - 1][j - k] + w[i][k]);
                
     cout << f[n][m] << endl;
     
 
     int v = m;//从前i中选，体积不超过v的 方案
     for(int i = n; i >= 1; -- i)
        for(int k = 0; k <= v; ++ k)//
            if(f[i-1][v - k] + w[i][k] == f[i][v])
            //v-k + k == v， f[i-1][v - k] + w[i][k] == f[i][v]
            //两个等式确定第i个物品选几个
            //也许有多个方案都能达到MAX，但我们只取其中一个
            {
                way[i] = k;
                v -= k;
                break;
            }
            
    for(int i = 1; i <= n; ++ i) cout << i << ' ' << way[i] << endl;
    
    return 0;
}