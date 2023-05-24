

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010, V = 20010;

//f[i][j] : 前i， 体积不超过j， 最大价值
//不选i：f[i-1][j]
//选i  ：max{f[i-1][j-kv] + kw}

/*
* 多重背包问题无法像完全背包一样优化， 因为转移方程中的元素无法完全覆盖
* 但是可以发现，转移方程里 体积那一维(第二维) 都是同余的值
* 我们可以枚举物品i的体积余数(0~v-1)，分成v类
* 然后再递增枚举同余的体积， 同时维护一个单调队列，窗口大小为(1~s)
* 1. 不同余的体积互相不干扰
* 2. 先枚举余数， 再递增枚举体积，共V次遍历， N * V
* 3. 单调队列的性质可以保证，枚举到j时， 队头一定是 max{f[i-1][j-kv] + kw}
* 4. //https://www.acwing.com/solution/content/53507/
*/

// int f[N][V];
// int v[N], w[N], s[N];

int dp[V], bg[V];

int q[V];
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;

    // for(int i = 1; i <= n; ++ i) scanf("%d%d%d", &v[i], &w[i], &s[i]);//必须去掉io优化
    //for (int i = 1; i <= n; ++ i) cin >> v[i] >> w[i] >> s[i];
    // for(int i = 1; i <= n; ++ i)//前i中选
    // {
    //     for(int r = 0; r < v[i]; ++ r)//枚举余数
    //     {
    //         int hh= 0, tt= -1;//构建单调队列
            
    //         for(int j = r; j <= m; j += v[i])//枚举余数为r的体积
    //         {
    //             //去头：当前体积为j，理论最多可以放 s[i]个体积为v[i] 的物品i
    //                   //则最左端元素的体积至少为 q[hh] >= j - v[i]*s[i], 因为队列里最多存在s[i]个元素
    //                   //比它还小，说明 队头元素不在[0,k]里
    //             while(hh <= tt && j - q[hh] > s[i] * v[i]) ++ hh;
    //             //去尾： 如果队尾元素的最大值， 小于当前最大值， 那它一定不会是窗口最大值
    //             while(hh <= tt && f[i-1][q[tt]] + ((j - q[tt]) / v[i] * w[i]) <= f[i-1][j]) -- tt;
    //             //入队
    //             q[++ tt] = j;
    //             //更新：窗口只有最大限制，最小为1；更新时需要加上被舍弃的权重
    //             f[i][j] = f[i-1][q[hh]] + ((j - q[hh]) / v[i] * w[i]);
    //         }
    //     }
    // }
    // cout << f[n][m] << endl;
    
    
    //i层的更新依赖i-1层：需要后序；i-1层的单调队列需要前序
    //所以需要备份数组
    for(int i = 1; i <= n; ++ i)//前i中选
    {
        int v, w, s; cin >> v >> w >> s;
        memcpy(bg, dp, sizeof dp);
        for(int r = 0; r < v; ++ r)//枚举余数
        {
            int hh= 0, tt= -1;//构建单调队列
            
            for(int j = r; j <= m; j += v)//枚举余数为r的体积
            {
                //去头：当前体积为j，理论最多可以放 s[i]个体积为v[i] 的物品i
                      //则最左端元素的体积至少为 q[hh] >= j - v[i]*s[i], 因为队列里最多存在s[i]个元素
                      //比它还小，说明 队头元素不在[0,k]里
                while(hh <= tt && j - q[hh] > s * v) ++ hh;
                //去尾： 如果队尾元素的最大值， 小于当前最大值， 那它一定不会是窗口最大值
                while(hh <= tt && bg[q[tt]] + ((j - q[tt]) / v * w) <= bg[j]) -- tt;
                //入队
                q[++ tt] = j;
                //更新：窗口只有最大限制，最小为1；更新时需要加上被舍弃的权重
                dp[j] = bg[q[hh]] + ((j - q[hh]) / v * w);
            }
        }
    }
    cout << dp[m] << endl;
    
    return 0;
}