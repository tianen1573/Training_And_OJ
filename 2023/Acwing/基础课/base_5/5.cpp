//二进制优化优化的是k层循环， 即我们把第i中物品，根据其个数，合并成不同的物品，
//使得这些物品也能表示出第i中物品，从0到k，能代表的体积和价值
//比如，有一个物品，体积为2，价值为3，有4个，则我们分成四种物品,即：[2,3], [4,6],[6,9],[8,12]
//但是我们发现，只需要[2,3],[4,6]即可,后面两个是可以由前面得到的
//整体思想就是：空间换时间，本来我们需要遍历才能得到第i个物品能得到的【体积，权重】集合
//通过预先处理，时间复杂度从 n*m*s[i]  -- > n*log(s[i])*m， 使其变成01背包
//详情看评论区

#include <cstdio>
#include <iostream>

using namespace std;

const int N = 12211, M = 2011; //N是优化后的 N = n * log(s[i])

int v[N], w[N];
int f[M];

int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    
    int cnt = 0;
    for(int i = 0; i < n; ++ i)
    {
        int a, b, s; cin >> a >> b >> s;
        
        //进行二进制优化
        int k = 1;
        while(k <= s)
        {
            v[++ cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
            k *= 2;
        }
        if(s > 0)
        {
            v[++ cnt] = a * s;
            w[cnt] = b * s;
        }
    }
    
    n = cnt;//优化后的物品个数
    
    //此时 多重背包就变成了01背包
    for(int i = 1; i <= n; ++ i)
        for(int j = m; j >= v[i]; -- j)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
            
    cout << f[m];
    
    return 0;
}