#include <iostream>
#include <cstring>
using namespace std;

int t, l, n;

int main()
{
    cin >> t;
    for(int ii = 1; ii <= t; ++ ii)
    {
        cin >> l >> n;
        
        char cur;
        long long dist = 0, cnt = 0;//dist和d的正负代替方向
        int d;
        
        for(int i = 1; i <= n; ++ i)
        {
            cin >> d >> cur;
           
            if('A' == cur) d *= -1;
            dist += d;
            cnt += abs(dist) / l;
            dist %= l;
        }
        
        printf("Case #%d: %lld\n", ii, cnt);
    }
    return 0;
}