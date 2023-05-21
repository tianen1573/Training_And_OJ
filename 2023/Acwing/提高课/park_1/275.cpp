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



/*
1. 暴力枚举：即求分开走(两次贪心-局部最优解)，也求同时走(全局最优解)，可得全局最优解
因为 全局最优解 大于等于 局部最优解，所以优化暴力枚举，只判断同时走
同时走代表两次路径的步数一样，代表 i1+j1 == i2+j2 == k
2. 同时走，用k代表纵横下标之和，特判两条路径经过相同点
3. 如果不允许一个节点经过两次，发现和 允许经过两次但只统计一次权重 是等价的
https://www.acwing.com/solution/content/12389/
*/

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 57;

int g[N][N];

int dp[N*2][N][N];

int n,m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j) cin >> g[i][j];
        
    //拓扑序：先小步再大步,逐渐压缩右下角的矩阵
    for(int k = 2; k <= n + m; ++ k)//2n-2+1步
        for(int i1 = 1; i1 <= n; ++ i1)
            for(int i2 = 1; i2 <= n; ++ i2)
            {
                int j1 = k - i1, j2 = k - i2;
                
                if(j1 >= 1 && j1 <= m && j2 >= 1 && j2 <= m)
                {
                    int &cur = dp[k][i1][i2];
                    int t = g[i1][k - i1];
                    if(i1 != i2) t += g[i2][k - i2];
                    
                    cur = max(cur, dp[k - 1][i1-1][i2-1] + t);
                    cur = max(cur, dp[k - 1][i1-1][i2] + t);
                    cur = max(cur, dp[k - 1][i1][i2-1] + t);
                    cur = max(cur, dp[k - 1][i1][i2] + t);
                }
            }
            
        cout << dp[n + m][n][n];//[n+m][n][n]，代表两条路径走到了第n行第(m == n+m-n)列,
    
    return 0;
}