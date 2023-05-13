#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1011;

int f[N][N];
int v[N], w[N];

int F[N];

int n, vol;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> vol;
    
    for(int i = 1; i <= n; ++ i)
        cin >> v[i] >> w[i];
    
    // for(int i = 1; i <= n; ++ i)
    //     for (int j = 1; j <= vol; ++ j )
    //     {
    //         f[i][j] = f[i - 1][j];//无物品i一定存在
    //         if(j >= v[i])//有物品i不一定存在
    //             f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
    //     }
    // cout << f[n][vol];
    
    //我们可以看的，在判断第i个物品时，只用到了其上一层i-1层的数据
    //则我们可以使用备份数组或者滚动数组来减少开辟数组空间
    //这里我们仅使用了当前数组来更新第i层，
    //如果我们从前往后使用[v[i] ~ vol]，则[j - v[i]]可能是第i层的数据
    //如果我们从后往前使用[vol ~ v[i]]，则[j - v[i]]可以保证一定是第i-1层的数据
    for(int i = 1; i <= n; ++ i)
        for(int j = vol; j >= v[i]; -- j)
            F[j] = max(F[j], F[j - v[i]] + w[i]);
    cout << F[vol];
    
    
    return 0;
}