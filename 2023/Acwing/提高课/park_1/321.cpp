#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 16;//最多到16

int s[N][N];//前缀和
double f[N][N][N][N][N];//f[x1,y1,x2,y2,k]
double X;

int n, m = 8;

double get(int x1, int y1, int x2, int y2)
{
    double delta = s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];
    
    delta -= X;
    return delta * delta;
    
}

double dp(int x1, int y1, int x2, int y2, int k)
{
    double &v = f[x1][y1][x2][y2][k];
    if(v >= 0) return v;//记忆化搜索
    if(k == 1) return v = get(x1, y1, x2, y2);//最后一块
    
    v = 0x3f3f3f3f;
    
    //竖切
    for(int i = y1; i < y2; ++ i)
    {
        v = min(v, get(x1, y1, x2, i) + dp(x1, i + 1, x2, y2, k - 1));//保留右边
        v = min(v, get(x1, i + 1, x2, y2) + dp(x1, y1, x2, i, k - 1));
    }
    
    //横切
    for(int i = x1; i < x2; ++ i)
    {
        v = min(v, get(x1, y1, i, y2) + dp(i + 1, y1, x2, y2, k - 1));//保留下边
        v = min(v, get(i + 1, y1, x2, y2) + dp(x1, y1, i, y2, k - 1));
    }
    
    return v;
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i = 1; i <= m; ++ i)
        for(int j = 1; j <= m; ++ j) cin >> s[i][j];
    
    for(int i = 1; i <= m; ++ i)
        for(int j = 1; j <= m; ++ j)
            s[i][j] += (s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1]);
    
    memset(f, -1, sizeof f);//合法状态可能为0， 初始化为-1
    
    X = (double) s[m][m] / n;//
    
    
    printf("%.3lf", sqrt(dp(1, 1, m, m, n) / n));
    
    return 0;
}
