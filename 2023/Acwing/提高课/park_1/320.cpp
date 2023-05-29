#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 211;

int f[N][N];

int w[N];

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for(int i = 1; i <= n; ++ i)
    {
        cin >> w[i];
        w[i + n] = w[i];
    }
    
    for(int len = 3; len <= n + 1; ++ len)//至少2个节点 到 至少 n个节点 --》至少3个数据 到 至多n+1个数据
        for(int i = 1; i + len  - 1 <= 2 * n; ++ i)
        {
            int l = i, r = i + len - 1;
            
            //本题是三个数据描述两个节点
            for(int k = l + 1; k < r; ++ k)
                f[l][r] = max(f[l][r], f[l][k] + f[k][r] + w[l]*w[k]*w[r]);
        }
    
    int maxv = -0x3f3f3f3f;
    for(int i = 1; i <= n; ++ i) maxv = max(maxv, f[i][i+n]);
    cout << maxv;
    
    return 0;
}
