#include <cstdio>
#include <iostream>

using namespace std;

const int N = 111;

int v[N][N], w[N][N], s[N];
int f[N];
// int f[N][N];

int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i)
    {
        cin >> s[i];
        for(int j = 1; j <= s[i]; ++ j)
         cin >> v[i][j] >> w[i][j];
    }
    
    // //f[i][j] = max(f[i-1][j-v[i][k] + w[i][k])
    // for(int i = 1; i <= n; ++ i)
    //     for(int j = 0; j <= m; ++ j)
    //     {
    //         f[i][j] = f[i - 1][j];//需要放在外面，保证只初始化一次，如果放在k循环里面，会随着物品更新，不符合要求
    //         for(int k = 1; k <= s[i]; ++ k)
    //             if(v[i][k] <= j && f[i][j] < f[i - 1][j - v[i][k]] + w[i][k])
    //                 f[i][j] = f[i - 1][j - v[i][k]] + w[i][k];
    //     }
    // cout << f[n][m];
    
    //优化数组
    for(int i = 1; i <= n; ++ i)//第i组
        for(int j = m; j >= 0; -- j)//不超过j空间，从后往前，保证更新的数据来源来自上一层
            for(int k = 1; k <= s[i]; ++ k)//第i组由k个物品，选其中一个
                if(v[i][k] <= j)
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
                    
    cout << f[m];
    
    return 0;
}