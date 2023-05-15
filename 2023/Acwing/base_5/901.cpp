#include <cstdio>
#include <iostream>

#include <cstring>

using namespace std;

const int N = 310;

int f[N][N];
int g[N][N];

int r, c;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int dfs(int x, int y)
{
    //从一个点出发，深搜这条路可以到的所有节点
    //并且返回记录，某个节点未开始能到达的最大距离
    
    //记忆化搜索， 保证一个位置只搜索一次，统计一次
    if(f[x][y] != -1) return f[x][y];
    
    int &v = f[x][y];
    
    v = 1;
    for(int i = 0; i < 4; ++ i)
    {
        int a = x + dx[i], b = y + dy[i];
        
        if(a >= 1 && a <= r && b >= 1 && b <= c && g[x][y] > g[a][b])//不越界 + (x,y)高于(a,b)
            v = max(v, dfs(a,b) + 1);
    }
    
    return v;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    memset(f, -1, sizeof f);
    
    cin >> r >> c;
    for(int i = 1; i <= r; ++ i)
        for(int j = 1; j <= c; ++ j)
            cin >> g[i][j];
    
    int res = 0;
    for(int i = 1; i <= r; ++ i)
        for(int j = 1; j <= c; ++ j)
            res = max(res, dfs(i, j));
            
    cout << res;
    
    return 0;
}