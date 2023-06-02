#include <iostream>
#include <cstring>

using namespace std;

const int N = 35;

int f[N][N];
int arr[N], len;

int l, r;

int dp(int pos, int pre, int lead, int limit)
{
    if(pos == 0) return 1;
    if(!limit && !lead && ~f[pos][pre]) return f[pos][pre];
    
    int res = 0, up = limit ? arr[pos] : 9;
    for(int i = 0; i <= up; ++ i)
    {
        if(abs(i - pre) < 2) continue;
        
        if(lead && (i == 0))//继续存在前导零
            res += dp(pos - 1, -2, 1, limit && (i == up));
        else //不存在前导零
            res += dp(pos - 1, i, 0, limit && (i == up));
    }
    
    return limit ? res : (lead ? res : f[pos][pre] = res);
}

int cal(int x)
{
    memset(f, -1, sizeof f);
    len = 0;
    
    while(x)
        arr[++ len] = x % 10, x /= 10;
    
    return dp(len, -2, 1, 1);
}

int main()
{
    cin >> l >> r;
    cout << cal(r) - cal(l - 1) << endl;
    
    return 0;
}