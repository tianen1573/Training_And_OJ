/*
分开走：第一次走完之后，第二次再走，求出来的是两个局部最优解
同时走：第一人在走的时候，第二人路径也在走，求出来的是全局最优解
https://www.acwing.com/problem/content/discussion/content/7201/

对于同时走：因为不存在负值，最优解的情况下，只允许入口出口走两次
https://www.acwing.com/solution/content/12389/
*/

//f[i1,j1,i2,j2]//表示第一条路径走到(i1,j1)，第二条路径走到(i2,j2)时，最大值
//f[i1,j1,i2,j2]：第一条路径所在的点称之为x点，另一条称之为y
//则f[x,y]可以由四个位置转移而来，x的上左，y的上左
//f[i1,j1,i2,j2] = max{f[i1-1,j1,i2-1,j2], f[i1-1,j1,i2,j2-1], f[i1,j1-1,i2-1,j2], f[i1,j1-1,i2,j2-1]};
//如果x，y在同一个点，统计x的值，否则统计x+y

/*
上述是暴力枚举，即求了分开走，又求了同时走，同时走 大于等于 分开，也可求出答案
还有一种方法是只求同时走，两条路径走相同步数 k == i1+j1==i2+j2, j1 = k - i1, j2 = k - i2
此时i1+j1 == i2+j2, 则我们可以用三个数表示 
f[k,i1,i2]: 走了k-1步，第一条路径在(i1, k-i1), 第二条路径在(i2, k-i2) 时的最大值
同样的，也是四个位置转移而来
f[k,i1,i2] = max{f[k-1, i1-1, i2-1], f[k-1, i1-1, i2], f[k-1, i1, i2-1], f[k-1, i1, i2]};//对应上面的
*/

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 11;

int f[N][N][N][N];//i1,j1,i2,j2
int g[N][N];

int dp[N*2][N][N];

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    int r,c,w;
    while(cin >> r >> c >> w, r && c && w)
    {
        g[r][c] = w;
    }
    
    // for(int i1 = 1; i1 <= n; ++ i1)
    //     for(int j1 = 1; j1 <= n; ++ j1)
    //         for(int i2 = 1; i2 <= n; ++ i2)
    //             for(int j2 = 1; j2 <= n; ++ j2)
    //             {
    //                 //if(i1 + j1 != i2 + j2) continue;//推导f[k,i1,i2]
                    
    //                 int &cur = f[i1][j1][i2][j2];
    //                 int t = g[i1][j1];
    //                 if(i1 != i2 || j1 != j2) t += g[i2][j2];
                    
    //                 cur = max(cur, f[i1-1][j1][i2-1][j2] + t);
    //                 cur = max(cur, f[i1-1][j1][i2][j2-1] + t);
    //                 cur = max(cur, f[i1][j1-1][i2-1][j2] + t);
    //                 cur = max(cur, f[i1][j1-1][i2][j2-1] + t);
    //             }
    
    // cout << f[n][n][n][n] << endl;
    
    //拓扑序：先小步再大步,逐渐压缩右下角的矩阵
    for(int k = 2; k <= n + n; ++ k)//2n-2+1步
        for(int i1 = 1; i1 <= n; ++ i1)
            for(int i2 = 1; i2 <= n; ++ i2)
            {
                //if(i1 == i2 && i1 != n && i1 != 1) continue;//只允许入口出口走两次
                int j1 = k - i1, j2 = k - i2;
                
                if(j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n)
                {
                    int &cur = dp[k][i1][i2];
                    int t = g[i1][j1];
                    if(i1 != i2) t += g[i2][j2];
                    
                    cur = max(cur, dp[k - 1][i1-1][i2-1] + t);
                    cur = max(cur, dp[k - 1][i1-1][i2] + t);
                    cur = max(cur, dp[k - 1][i1][i2-1] + t);
                    cur = max(cur, dp[k - 1][i1][i2] + t);
                }
            }
            
        cout << dp[n + n][n][n];
    
    return 0;
}