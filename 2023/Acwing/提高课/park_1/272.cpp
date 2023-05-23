//f[i,j]: 从 a序列的前i个元素，b序列的前j个元素 种选择， 并且以 b[j]结尾 的 最长公共上升子序列
//转移状态：我们以bi]结尾，所以b[i]是必选的，所以状态转移讨论需不需要选a[i]
//0.若a[i] != b[i], a[i]是肯定不选的,f[i][j] = f[i-1][j]
//1.若a[i] == b[i], 并且不选a[i], f[i][j] = f[i-1][j]
//2.若a[i] == b[i], 并且选a[i], f[i][j] = max{f[i-1][k(1~j-1)]+1，b[j]> b[k]}，前者是集合，后者是条件

#include <cstdio>
#include <iostream>

using namespace std;

const int N = 3010;

int a[N], b[N], f[N][N];

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; ++ i) cin >> a[i];
    for(int i = 1; i <= n; ++ i) cin >> b[i];
    
    /*
    //暴力dp -- TLE
    int res = 0;
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= n; ++ j)
        {
            f[i][j] = f[i - 1][j];
            
            if(a[i] == b[j])
            {
                for(int k = 0; k <= j - 1; ++ k)
                    if(b[k] < b[j])
                        f[i][j] = max(f[i][j], f[i-1][k] + 1);
            }
            
            res = max(res, f[i][j]);
        }
    cout << res;
    */
    
    /*
    * 可以发现：a[i] == b[j], 则 b[k] < a[i]; 并且 f[i][j] 是通过 f[i-1][1~j-1]更新的
    * f[i][j-1] 是通过 f[i-1][1~j-1-1] 更新的 ...
    * 我们默认一个maxv 代表 a[i]固定时 1~j 的最大上升公共子序列长度
    * 若 a[i] == b[j], 为替换，当前 j 替换maxv时的 j
        则 f[i][j] = max(f[i][j], maxv);（f[i][j]初始化为f[i-1][j]， 即不选a[i], max{选a[i]}）
    * 若 a[i] > b[j], 为追加，当前 j 可以是 最长公共上升子序列的倒数第二个元素, 
                                        a[i] == b[j]时的j 就可以追加到这个j的后面
        则maxv可能会发生更新， maxv = max(maxv, f[i][j] + 1)
    * 若 a[i] < b[j] 不符合上升子序列
    */
    int res = 0;
    for(int i = 1; i <= n; ++ i)
    {
        int maxv = 1;
        for(int j = 1; j <= n; ++ j)
        {
            f[i][j] = f[i - 1][j];
            if(b[j] == a[i]) f[i][j] = max(f[i][j], maxv);//代表可替换
            if(b[j] < a[i]) maxv = max(maxv, f[i][j] + 1);//代表可最为倒数第二个元素
            
            res = max(res, f[i][j]);
        }
    }
    cout << res;
    
    // for(int i = 1; i <= n; ++ i)
    // {
    //     for(int j = 1; j <= n; ++ j)
    //         cout << f[i][j] << ' ';
    //     cout << endl;
    // }
    return 0;
}
