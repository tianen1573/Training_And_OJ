//f[i][j]: 从前i个数选，和刚好等于j 的方案数
//不选i： f[i-1][j]
//选i  ： {f[i-1][j-v], f[i-1][j-2v], ..., f[i-1][j-kv]} == f[i][j-v]
//加起来

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010;

int f[N];

int n;

int h[5] = {0, 10, 20, 50, 100};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    f[0] = 1;//初始化
    for(int i = 1; i <= 4; ++ i)
    {
        for(int j = h[i]; j <= n; ++ j)
            f[j] += f[j - h[i]];
    }
    
    cout << f[n];
    
    return 0;
}
