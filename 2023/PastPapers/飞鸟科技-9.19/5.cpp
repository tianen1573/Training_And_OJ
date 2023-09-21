#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
typedef vector<vector<ll>> mat;     

mat mul(mat &a, mat &b)
{
    mat ret(a.size(), vector<ll>(b[0].size(), 0));
    // 矩阵乘法
    for(int i = 0; i < a.size(); ++ i)
        for(int j = 0; j < b[0].size(); ++ j)
            for(int k = 0; k < a[0].size(); ++ k)
                ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % MOD;

    return ret;
}

mat pow(mat a, ll n)
{
    // 定义并初始化成单位矩阵
    mat res(a.size(), vector<ll>(a[0].size()));
    for(int i = 0; i < a.size(); ++ i)
            res[i][i] = 1;
    
    // 快速幂
    while(n)
    {
        if(n & 1)
            res = mul(res, a);
        a = mul(a, a);
        n /= 2;
    }

    return res;
}

void solve(ll n)
{
    vector<ll> base{3,2,1}; // 最初的元素f(3),f(2),f(1)
    mat mm(3, vector<ll>(3)); // 根据dp公式，构建矩阵
    mm[0][0] = 1, mm[0][1] = 0, mm[0][2] = 1;
    mm[1][0] = 1, mm[1][1] = 0, mm[1][2] = 0;
    mm[2][0] = 0, mm[2][1] = 1, mm[2][2] = 0;
	
    // 矩阵快速幂
    mat pmat = pow(mm, n - 3);
	
    // 求f(n)
    ll ans = 0;
    for(int i = 0; i < 3; ++ i)
        ans = (ans + base[i] * pmat[0][i]) % MOD;
    
    cout << ans;
}

int main() {
    
    long long n;
    cin >> n;
    if(n <= 3)
        cout << n;
    else
        solve(n);
    
    return 0;
}
// 64 位输出请用 printf("%lld")