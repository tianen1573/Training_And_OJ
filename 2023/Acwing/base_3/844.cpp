#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;


const int N = 111;

int que[N * N][2], hh = 0, tt = -1;//注意队列大小
bool g[N][N], st[N][N];


int dir[4][2] = {-1,0, 0,1, 1,0, 0,-1};

int n, m;


void bfs()
{
    que[++ tt][0] = 1, que[tt][1] = 1;
    st[1][1] = true;
    
    int res = 0;
    while(hh <= tt)//bfs层序
    {
        int ttt = tt;
        while(hh <= ttt)
        {
            int r = que[hh][0], c = que[hh++][1];
        
            if(r == n && c == m) 
                goto nihao;//终点
            
            for(int d = 0; d < 4; ++ d)
            {
                int x = r + dir[d][0];
                int y = c + dir[d][1];
                
                
                //g[x][y]，为墙时，值为1
                //st[x][y]，未被遍历时，值为1
                if(!g[x][y] && st[x][y])
                {
                    st[x][y] = false;
                    que[++ tt][0] = x, que[tt][1] = y;//入队
                }
            }
        }
        //下一步
        ++ res;
    }
    
    nihao:
        cout << res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); 
    std::cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
        {
            cin >> g[i][j];
            st[i][j] = 1;
        }
    
    // for(int i = 1; i <= n; ++ i)
    // {
    //     for(int j = 1; j <= m; ++ j)
    //     {
    //         cout << g[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    
    bfs();
            
    return 0;
}