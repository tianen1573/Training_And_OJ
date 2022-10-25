

// 小易来到了一条石板路前，每块石板上从1挨着编号为:1、2、3.......
// 这条石板路要根据特殊的规则才能前进:对于小易当前所在的编号为K的石板，小易单次只能往前跳K的一个约数(不含1和K)步，
// 即跳到K+×(X为K的一个非1和本身的约数)的位置。小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，
// 小易想知道最少需要跳跃几次可以到达。
// 例如:
// N= 4，M= 24:4->6->8->12->18->24
// 于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板

// 动态规划

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;

int dp[100011];

int main() {
    int n, m;
    cin >> n >> m;

    //memset(dp, 0x3f, sizeof(int) * (m + 1));
    //cout << dp[0];

    dp[n] = 1;
    for (int i = n; i < m; ++i) {
        if (dp[i]) 
        {
            for (int j = 2; j <= sqrt(i); j ++) //算术平方根可过， 除以2 不行
            {
                if (i % j == 0) {
                    int ij = i / j;
                    
                    if (i + j <= m)
                    {
                        dp[i + j] = dp[i + j] ? min(dp[i + j], dp[i] + 1) : dp[i] + 1;
                    }
                        
                    if (i + ij <= m)
                    {
                        dp[i + ij] = dp[i + ij] ? min(dp[i + ij], dp[i] + 1) : dp[i] + 1;
                    }
                }
            }
        }
    }
    if (dp[m] == 0)
        cout << "-1";
    else
        cout << dp[m] - 1;

    return 0;
}