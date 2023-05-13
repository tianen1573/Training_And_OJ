#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1011;

int f[N][N];
int w[N], v[N];
int F[N];

int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i) cin >> v[i] >> w[i];
    
    // //TLE
    // for(int i = 1; i <= n; ++ i)//1. 从第一个物品到第n个物品
    //     for(int j = 1; j <= m; ++ j)//2. 体积不超过j
    //         for(int k = 0; k * v[i] <= j; ++ k)//3. 状态转移第i个物品拿几个
    //             f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);
    
    // //优化k循环 -- f[i][j] = max(f[i-1][j], f[i][j-v[i] + w[i]);
    // for(int i = 1; i <= n; ++ i)//1. 从第一个物品到第n个物品
    //     for(int j = 1; j <= m; ++ j)//2. 体积不超过j
    //     {
    //         f[i][j] = f[i - 1][j];
            
    //         if(j >= v[i])
    //             f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
    //     }
    
    // cout << f[n][m];
    
    //优化数组 -- F[j] = max(F[j], F[j - v[i]] + w[i]);
    //分析优化k循环循环， 可以发现 f[i][j] = f[i - 1][j] 是一定执行的
    //并且，在后续的更新中，f[i][j] 是在第i层数据更新的
    //则前面较小的j更新时，后面较大的j更新是依靠这个较小的j的
    //所以，这里我们从v[i]遍历到m
    //和01背包是由区别的
    for(int i = 1; i <= n; ++ i)
        for(int j = v[i]; j <= m; ++ j)
            F[j] = max(F[j], F[j - v[i]] + w[i]);
        
    cout << F[m];
    
    
    return 0;
}