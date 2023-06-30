#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1e9 + 7;

int T;

long long modpow(long long x, long long k)//二分求幂
{
    if(k == 0) return 1;
    long long mod = modpow(x, k >> 1);
    mod = mod * mod % MOD;
    if(k & 1) mod = mod * x % MOD;
    
    return mod;
}

int main()
{
    cin >> T;
    for(int t = 1; t <= T; ++ t)
    {
        int n, k;
        string str;
        cin >> n >> k >> str;
        
        //类似于y老师讲数字DP时的分析方法，画树
        long long ans = 0;
        // 只判断字符串前半部分
        int mid = (n - 1) / 2;
        for(int i = 0; i <= mid; ++ i)
        {
            ans += (str[i] - 'a') * modpow(k, mid - i);//小于str[i]一定是成立的字符串
            ans %= MOD;
        }
        //特判左半部分顶格模拟时，右半部分是否越格
        int left, rig;
        bool flag = false;//因为是小于，所以等于S时不成立
        if(n % 2 == 0) left = mid, rig = mid + 1;
        else left = mid - 1, rig = mid + 1;
        while(left >= 0)
        {
            if(str[left] != str[rig])//左边顶格处理了，所以左右不相等时，才代表这个最大字符串不等于S
            {
                flag = str[left] < str[rig];//左小于右才满足最大字符串小于S
                break;
            }
            left --, rig ++ ;
        }
        if(flag) ++ ans;
        ans %= MOD;
        
        printf("Case #%d: %lld\n", t, ans % MOD);
    }
    
    // cout << modpow(2, 3) << endl;
    return 0;
}
