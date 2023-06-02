#include <iostream>
#include <cstring>

using namespace std;

const int N = 211;//位数和

int f[N][N];
int arr[N], len;

int l, r;

int dp(int pos, int pre, int limit)
{
    if(pos == 0) return 1;
    if(!limit && ~f[pos][pre]) return f[pos][pre];
    
    int res = 0, up = limit ? arr[pos] : 9;
    for(int i = 0; i <= up; ++ i)
    {
        if(i == 4) continue;
        if(pre == 6 && i == 2) continue;
        
        res += dp(pos - 1, i, limit && (i == up));
    }
    
    return limit ? res :f[pos][pre] = res;
}

int cal(int x)
{
    memset(f, -1, sizeof f);
    len = 0;
    
    while(x)
        arr[++ len] = x % 10, x /= 10;
    
    return dp(len, 0, 1);
}

int main()
{
    while(cin >> l >> r, l && r)
    {
        cout << cal(r) - cal(l - 1) << endl;
    }

    return 0;
}