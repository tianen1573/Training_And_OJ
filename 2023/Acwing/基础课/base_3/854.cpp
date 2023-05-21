#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
const int N = 211;

int d[N][N];

int n, m, k;


void floyd()
{
    //经过k点， 从i到j
    for(int k = 1; k <= n; ++ k)
        for(int i = 1; i <= n; ++ i)
            for(int j = 1; j <= n; ++ j)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m >> k;
    
    //0. 处理图
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            if (i == j) d[i][j] = 0;
            else d[i][j] = 1e9;
    
    //1. 读取边
    while(m -- )
    {
        int a, b ,c; cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }
    //2. 更新
    floyd();
    
    while(k --)
    {
        int a, b; cin >> a >> b;
        if(d[a][b] > 1e9 / 2) cout << "impossible" << endl;//逻辑上的不连接
        else cout << d[a][b] << endl;
    }
    
    return 0;
}