// #include <iostream>
// #include <cstring>
// #include <cstdlib>

// using namespace std;

// const int N = 1e2 + 1;
// //f[i][j][k]: 第i步，cnt为j时，花为k时 的最小花费 -- TLE
// int f[N][N], bup[N][N];
// int t, n;

// int main()
// {
//     cin >> t;
//     for(int ii = 1; ii <= t; ++ ii)
//     {
//         memset(f, 0x3f, sizeof f);
//         f[0][0] = 0;
        
//         cin >> n;
        
//         int res = 0x3f3f3f3f;
//         for(int i = 1; i <= n; ++ i)
//             for(int k = 1; k <= n; ++ k)
//             {
//                 for(int j = 0; j <= k; ++ j)
//                 {
//                     memcpy(bup, f, sizeof f);
//                     f[j][k] = min(bup[j][k - 1] + 1, bup[j][k - j] + 2);
//                     for(int kk = 0; kk <= k; ++ kk)
//                         f[k][k] = min(f[k][k], bup[kk][k] + 4);
                        
//                     if(k == n) res = min(res, f[j][k]);
//                 }
                
//             }
        
        
            
//         printf("Case #%d: %d\n", ii, res);
//     }
    
//     return 0;
// }

// 作者：trudbot
// 链接：https://www.acwing.com/solution/content/150198/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int dp[N];

int main () {
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;

    for (int i = 1; i < N; i ++) {
        dp[i] = min(dp[i], dp[i-1] + 1);
        for (int j = i + i, k = 1; j < N; j += i, k ++) {
            dp[j] = min(dp[j], dp[i] + 4 + 2 * k);
        }
    }

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        cout << "Case #" << t << ": " << dp[n] << endl;
    }

    return 0;
}

