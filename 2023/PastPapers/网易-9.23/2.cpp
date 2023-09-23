#include <iostream>
using namespace std;

int main() 
{
    int n, m, p;
    cin >> n >> m >> p;
    if(m == n)
    {
        cout << 1;
        return 0;
    }
    m -= (n + 1);
    int ans = 2;
    int l = max(1, p - 1);
    int r = min(n, p + 1);
    while(true)
    {
        int val = r - l + 1;
        if(m < val)
            break;
        m -= val;
        ++ ans;
        l = max(1, l - 1);
        r = min(n, r + 1);
    }
    
    cout << ans;
}
// 64 位输出请用 printf("%lld")