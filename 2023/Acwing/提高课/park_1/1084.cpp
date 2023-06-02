#include <iostream>
#include <cstring>

using namespace std;

const int N = 211;//位数和

int f[N][N];
int arr[N], len;

int l, r, p;

int dp(int pos, int sum, int limit)
{
    if(pos == 0) return sum % p == 0;
    if(!limit && ~f[pos][sum]) return f[pos][sum];
    
    int res = 0, up = limit ? arr[pos] : 9;
    for(int i = 0; i <= up; ++ i)
    {
        res += dp(pos - 1, sum + i, limit && (i == up));
    }
    
    return limit ? res :f[pos][sum] = res;
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
    while(cin >> l >> r >> p)
    {
        cout << cal(r) - cal(l - 1) << endl;
    }

    return 0;
}