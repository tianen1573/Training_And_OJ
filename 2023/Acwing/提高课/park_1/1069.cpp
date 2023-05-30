#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 53;

//f[i][j]: 从点i到点j 构成三角形 的方案 的 最小值
vector<int> f[N][N];//从 i 到 j 构成三角形 的 最小值, 并且高精度表示时， 数值低位 在 下标低位

int w[N];
int n;

bool cmp(vector<int> &a, vector<int> &b)
{
    if (a.size() != b.size()) return a.size() < b.size();
    for (int i = a.size() - 1; i >= 0; i -- )
        if (a[i] != b[i])
            return a[i] < b[i];
    return true;
}

vector<int> add(vector<int> &a, vector<int> &b)
{
    vector<int> c;
    
    int t = 0;
    for(int i = 0; i < a.size() || i < b.size(); ++ i)
    {
        if(i < a.size()) t += a[i];
        if(i < b.size()) t += b[i];
        
        c.push_back(t % 10);
        t /= 10;
    }
    
    while(t) c.push_back(t % 10), t /= 10;
    
    return c;
}

//本题大数相乘时，是 LL * LL * LL(1e9级别)
//右操作数可保证是LL，左操作数使用vector
vector<int> mul(vector<int> &a, long long b)
{
    vector<int> c;
    long long t = 0;
    for(int i = 0; i < a.size(); ++ i)
    {
        t += b * a[i];
        c.push_back(t % 10);
        t /= 10;
    }
    
    while(t) c.push_back(t % 10), t /= 10;
    
    return c;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; ++ i) cin >> w[i];
    
    vector<int> a = {1,2,3};
    vector<int> b = {1,2,3};
    auto  c = mul(a, 1);
    
    for(int len = 3; len <= n; ++ len)//三个点才能成三角形，所以3~n，从中选三个点构成三角形
    {
        for(int l = 1; l + len - 1 <= n; ++ l)
        {
            int r = l + len - 1;
            for(int k = l + 1; k < r; ++ k)
            {
                //mul
                vector<int> tmp; tmp.push_back(w[l]);
                tmp = mul(tmp, w[k]);
                tmp = mul(tmp, w[r]);
                //add
                tmp = add(tmp, f[l][k]);
                tmp = add(tmp, f[k][r]);
                
                if(f[l][r].empty() || cmp(tmp, f[l][r])) f[l][r] = tmp;
            }
        }
    }
    
    auto res = f[1][n];
    for(int i = res.size() - 1; i >= 0; -- i) cout << res[i];
    
    return 0;
}
