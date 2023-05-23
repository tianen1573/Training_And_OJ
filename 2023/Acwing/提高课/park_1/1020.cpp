#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 83, M = 23;

//f[i][j][k]: 从前i个中选，氧气至少为j，氮气至少为k，重量最小值
//不选i ： f[i-1][j][k];
//选i   ： f[i-1][j-v][k-t] + w;
    // 假设 j = 4， 此时来了一个体积为5的罐子， 4 - 5 < 0x3f
    // 但我们仍可以用这个罐子更新体积至少为4时的最少重量，而且这个罐子可以更新[0~4]的
    // 超了怎么办？超了放气放掉。。。
//关于初始化，因为选最小值，除了f[i][0][0], 其他都应该初始化为inf
//https://www.acwing.com/solution/content/38499/
//https://www.acwing.com/solution/content/7438/

int f[M][N], g[M][N];//氧气氮气

int n, m, k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;
    
    cin >> m >> n >> k;
    
    for(int t = 1; t <= k; ++ t)
    {
        int a, b, c; cin >> a >> b >> c;//痒，氮，重
        for(int i = m; i >= 0; -- i)
            for(int j = n; j >= 0; -- j)
                f[i][j] = min(f[i][j], f[max(0, i-a)][max(0, j-b)] + c);
    }
    
    cout << f[m][n];
    // cout << endl << 0x3f3f3f3f;
    
    return 0;
}


