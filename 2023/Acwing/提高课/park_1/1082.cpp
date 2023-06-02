#include <iostream>
#include <cstring>

using namespace std;

const int N = 35;

//记忆化的f[i][j]代表的是不贴上界，当前位置是i，之前的数是j的情况下的合法方案。
int arr[N], len;
int f[N][N];//深度为i，前一个数以j开头的，不下降方案数

int dp(int pos, int pre, int limit)
{
    //1. 边界
    if(pos == 0) return 1;
    //2. 记忆化
    //如果当前位置没有限制， 则可以返回 上一个位置结尾的方案数
    if(!limit && ~f[pos][pre]) return f[pos][pre];
    //3. 模拟区间
    int res = 0, up = limit ? arr[pos] : 9;
    for(int i = 0; i <= up; ++ i)
    {    
        if(i < pre) continue;
        
        res += dp(pos - 1, i, limit && (i == up));
    }
    
    return limit ? res : f[pos][pre] = res;
    
}

int cal(int x)
{
    len  = 0;
    memset(f, -1, sizeof f);
    
    while(x) arr[ ++ len] = x % 10, x /= 10;
    
    //不下降序列，初始为0
    return dp(len, 0, 1);
}

int main()
{
    int a, b;
    while(cin >> a >> b)
    {
        cout << cal(b) - cal(a - 1) << endl;
    }
    
    return 0;
}