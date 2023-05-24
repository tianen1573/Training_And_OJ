// 1. 完全背包+多重背包二进制优化
// 2. 将01背包/完全背包转换成多重背包, 01背包s置为1， 完全背包 s置为 m / v, 上取整
// 分类讨论+二进制优化

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010, M = 1010;

int f[M];

int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; ++ i)
    {
        int v, w, s; cin >> v >> w >> s;
        
        
        if(s == 0)//完全背包
        {
            for(int j = v; j <= m; ++ j)
                f[j] = max(f[j], f[j - v] + w);
        }
        else
        {
            if(s == -1)//01转多重
                s = 1;
            int h[16], t[16];
            int k = 1, cnt = 1;//若从1开始，后置++，需要在二进制化结束后-1； 0前置不需要
            
            while(k <= s)
            {
                h[cnt] = k * v;
                t[cnt++] = k * w;
                
                s -= k;
                k *= 2;
            }
            if(s > 0)
            {
                h[cnt] = s * v;
                t[cnt++] = s * w;
            }
            -- cnt;
            
            // cout << cnt << endl;
            for(int ii = 1; ii <= cnt; ++ ii)
                for(int j = m; j >= h[ii]; -- j)
                    f[j] = max(f[j], f[j - h[ii]] + t[ii]);
        
            // for(int k = 1; k <= s; k *= 2)
            // {
            //     for(int j = m; j >= k * v; -- j)
            //         f[j] = max(f[j], f[j - k * v] + k * w);
            //     s -= k;
            // }
            
            // if(s)
            //     for(int j = m; j >= s * v; -- j)
            //         f[j] = max(f[j], f[j - s * v] + s * w);
            
        }
        
    }
    
    cout << f[m];
    
    return 0;
}
