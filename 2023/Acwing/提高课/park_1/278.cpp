//f[i][j]: 从前i个数选，和刚好等于j 的方案数
//不选i： f[i-1][j]
//选i  ： f[i-1][j-v]
//加起来

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int M = 10010;

int f[M];

int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    f[0] = 1;//初始化
    for(int i = 1; i <= n; ++ i)
    {
        int val; cin >> val;
        
        for(int j = m; j >= val; -- j)
            f[j] += f[j - val];
    }
    
    cout << f[m];
    
    return 0;
}
