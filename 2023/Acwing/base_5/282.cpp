/*
f[i][j] : 从i到j， 合成一堆石头， 所需要的最少代价
f[i][j] --> min(f[i][k] + f[k+1][j] + s[j] - s[i-1], f[i][j]), k-->[i+1,j-1]

我们处理的是 两个堆合成一个堆，大于二个堆的合并会转化成两个堆的合并

注意：我们如果使用ijk三重循环去转移，会发现转移方程是具有矛盾的，
比如f[i][j]的转移方程里，有f[k+1][j], k+1>i，代表f[k+1][j]是在本次循环过程后初始化的
用一个后面初始化的数据初始化一个前面的未初始化数据，显然是矛盾的，看题解

所以我们需要改变循环过程，最外层我们用待合并的堆数来循环，则我们可以优先把堆数少的给初始化
而后面堆数大的初始化时，其转移方程就为合法的了
*/

#include <cstdio>
#include <iostream>

using namespace std;

const int N = 311;

int arr[N];
int dp[N][N];

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; ++ i) cin >> arr[i];
    for(int i = 1; i <= n; ++ i) arr[i] += arr[i -1];//将数组处理为前缀和数组
    
    
    for(int len = 2; len <= n; ++ len)//第一层，为合并的堆的个数，当堆数为1时，代价为0，直接跳过
        for(int i = 1; i + len - 1 <= n; ++ i)//第二层，为开始的堆的编号，结束的堆由编号+堆个数控制
        {
            int l = i, r = len + i - 1;//开始堆~结束堆
            //单堆，即自己和自己合并时，初始化为0；而多个堆合并时，初始化为无穷
            //因为我们通过循环，保证了先合并少的，再合并多的
            //即我们保证了f[l][r]，在整个循环里初始化一次，也可以在外面合并
            dp[l][r] = 1e9;
            for(int k = l; k < r; ++ k)//第三层循环，两堆合成一堆
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r] + arr[r] - arr[l - 1]);
        }
    
    cout << dp[1][n];
    
    return 0;
}