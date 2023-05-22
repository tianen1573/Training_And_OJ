#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1010;

int h[N], f[N], q[N];

int n = 1;

int  main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    while (cin >> h[n]) ++ n;
    -- n;
    
    /*
    
    //dp+离散
    int max_up = 1, max_down = 1;
    
    for(int i = 1; i <= n; ++ i) f[i] = 1;
    for(int i = n; i >= 1; -- i)
        for(int j = n; j > i; -- j)
            if(h[i] >= h[j])
            {
                f[i] = max(f[i], f[j] + 1);
                max_down = max(max_down, f[i]);
            }
    
    
    //一个序列至少需要多少不上升子序列覆盖 等价于 最长上升子序列的长度，反链定理
    for(int i = 1; i <= n; ++ i) f[i] = 1;
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j < i; ++ j)
            if(h[i] > h[j])
            {
                f[i] = max(f[i], f[j] + 1);
                max_up = max(max_up, f[i]);
            }
    
    
    cout << max_down << endl << max_up;
    */
    
    
    //贪心+dp
    //贪心：维护不上升子序列集合， 当一个导弹来临时，尽可能的把它放在 比它高的结尾里最小值的队列里
    int res = 1, cnt = 0;
    for(int i = 1; i <= n; ++ i)
    {
        f[i] = 1;
        
        for(int j = 1; j < i; ++ j)
            if(h[i] <= h[j])
                f[i] = max(f[i], f[j] + 1);
        res = max(res, f[i]);        
            
        int k = 0;
        while(k < cnt && q[k] < h[i]) ++ k;
        
        q[k] = h[i];
        if(k == cnt) cnt ++;
    }
    
    cout << res << endl << cnt;
    
    
    return 0;
}