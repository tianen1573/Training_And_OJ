
/*
f[i][j] : 从1~i中选， 并且和等于j的方案数
f[i][j] = f[i-1][j] + f[i][j-i];
初始化：f[0][0] = 0, 即一个不选何为0的情况
*/

#include<cstdio>
#include<iostream>

using namespace std;

const int N = 1010, MOD = 1e9+7;

int f[N];

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    f[0] = 1;//不选且和为0的状态
    
    for(int i = 1; i <= n; ++ i)//1. i是否选
        for(int j = i; j <= n; ++ j)//2. 和为j
            f[j] = (f[j] + f[j - i]) % MOD;//3. 转移
            
    cout << f[n];
    
    
    return 0;
}