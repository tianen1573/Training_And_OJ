#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int ans = INT_MAX;
vector<vector<char>> g;
vector<vector<bool>> st;
int n, m;
int dxy[5] = {0, 1, 0, -1, 0};
void bfs(int x, int y, int step, int h)
{
    if(h <= 0 || step >= ans)
        return ;
    if(x == n - 1 && y == m - 1)
    {
        ans = min(ans, step);
        return ;
    }

    st[x][y] = true;
    for(int i = 0; i < 4; ++ i)
    {
        int nx = x + dxy[i];
        int ny = y + dxy[i + 1];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m || st[nx][ny] || g[nx][ny] == '*')
            continue;
        
        bfs(nx, ny, step + 1, h - g[nx][ny] + '0');
    }
    st[x][y] = false;

    return ;
}

int main() 
{
    int h;
    cin >> n >> m >> h;
    // cout << n << m << h;
    g = vector<vector<char>>(n, vector<char>(m, ' '));
    st = vector<vector<bool>>(n, vector<bool>(m, false));

    int cnt = 0;

    getchar();
    for(int i = 0; i < n; ++ i)
    {
        for(int j = 0; j < m; ++ j)
        {
            scanf("%c", &g[i][j]);
            if(g[i][j] == '.')
                g[i][j] = '0';
            else
                ++ cnt;
        }
        getchar();
    }
    
    if(cnt == 0)
        cout << n + m - 2;
    else
    {
        bfs(0, 0, 0, h);
        if(ans == INT_MAX)
            ans = -1;
        cout << ans;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")