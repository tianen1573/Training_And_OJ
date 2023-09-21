// 超时原因：仅靠步数来进行递归终止是不够的，因为在前期，步数肯定小于ans，此时前期节点仍然会被重入，只能筛掉一些后期节点
// 对于一个节点，小红达到该地时有两个属性：[血量，步数]，如果使用[x,y,血量，步数]来进行记忆化搜索，其复杂度为12500000 = 1e7，会爆栈
// 但我们若以bfs宽搜的形式来遍历图，我们能够确保的是，当第一次以某个血量到达某地时，其步数一定是最小的(bfs特性)，而且第一次到达终点时，步数也一定是最小之一
// 则数据就可以优化为[x, y, 血量]，这样就可以筛掉节点的重复血量
// 如果我们把小红闯迷宫分成4个阶段，则step>ans，筛掉的是第4个+少量第3个
// bfs宽搜+数据，筛掉的是少量全部+大量3，4阶段
// int ans = INT_MAX;
// vector<vector<char>> g;
// vector<vector<bool>> st;
// int n, m;
// int dxy[5] = {0, 1, 0, -1, 0};
// void bfs(int x, int y, int step, int h)
// {
//     if(h <= 0 || step >= ans)
//         return ;
//     if(x == n - 1 && y == m - 1)
//     {
//         ans = min(ans, step);
//         return ;
//     }

//     st[x][y] = true;
//     for(int i = 0; i < 4; ++ i)
//     {
//         int nx = x + dxy[i];
//         int ny = y + dxy[i + 1];
//         if(nx < 0 || nx >= n || ny < 0 || ny >= m || st[nx][ny] || g[nx][ny] == '*')
//             continue;
        
//         bfs(nx, ny, step + 1, h - g[nx][ny] + '0');
//     }
//     st[x][y] = false;

//     return ;
// }

// int main() 
// {
//     int h;
//     cin >> n >> m >> h;
//     // cout << n << m << h;
//     g = vector<vector<char>>(n, vector<char>(m, ' '));
//     st = vector<vector<bool>>(n, vector<bool>(m, false));

//     int cnt = 0;

//     getchar();
//     for(int i = 0; i < n; ++ i)
//     {
//         for(int j = 0; j < m; ++ j)
//         {
//             scanf("%c", &g[i][j]);
//             if(g[i][j] == '.')
//                 g[i][j] = '0';
//             else
//                 ++ cnt;
//         }
//         getchar();
//     }
    
//     if(cnt == 0)
//         cout << n + m - 2;
//     else
//     {
//         bfs(0, 0, 0, h);
//         if(ans == INT_MAX)
//             ans = -1;
//         cout << ans;
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int ans = INT_MAX;
char g[51][51];
int st[51][51][51] = {0}; // 存放步数，0代表未访问
int n, m;
int dxy[5] = {0, 1, 0, -1, 0};
struct node
{
    int x, y, h;
};
queue<node> que;
int main() 
{
    // 读取
    int h;
    cin >> n >> m >> h;
    getchar();
    for(int i = 0; i < n; ++ i)
    {
        scanf("%s", &g[i]);
    }
    
    // 队列
    node head;
    node tmp;
    que.push({0, 0, h});
    st[0][0][h] = 1;

    // bfs
    while(que.size())
    {
        head = que.front();
        que.pop();
        // 四个方向
        for(int i = 0; i < 4; ++ i)
        {
            int nx = head.x + dxy[i];
            int ny = head.y + dxy[i + 1];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || g[nx][ny] == '*') // 位置非法
                continue;
            int nh = head.h;
            if(g[nx][ny] != '.')
                nh -= (g[nx][ny] - '0');
            if(nh <= 0 || st[nx][ny][nh]) // 血量非法
                continue;
            if(nx == n - 1 && ny == m - 1) // 第一次访问到终点，其结果一定是答案
            {
                cout << st[head.x][head.y][head.h]; // 起点步数为1，则终点不须技术
                return 0;
            }
            
            // 入队
            tmp.x = nx;
            tmp.y = ny;
            tmp.h = nh;
            st[nx][ny][nh] = st[head.x][head.y][head.h] + 1;
            que.push(tmp);
        }
    }
    
    cout << "-1";
    return 0;
}
