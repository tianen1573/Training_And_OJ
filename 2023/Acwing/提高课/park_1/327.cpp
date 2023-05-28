//markdown文档
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 14, M = 14, K = 1 << 13, MOD = 1e8;

int f[N][K];//f[i],前i行已经放，且第i行的状态为j时 的 方案数

//状态压缩基础数据结构
vector<int> st;//保存合法状态
vector<int> head[M];//保存合法状态 的 合法联通； 如第i行状态为a， 所有的合法i-1行状态b 都放进集合
//其他
int h[N];//土地肥沃

int n, m;

bool check(int state)
{
    for(int i = 0; i + 1 < m; ++ i)
        if((state >> i & 1) && (state >> (i + 1) & 1))//存在连续1
        // if(state & (state >> 1))
            return false;
    return true;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i)
        for(int j = 0; j < m; ++ j)
        {
            int s; cin >> s;
            h[i] |= !s * (1 << j);//+=,|=
        }
    
    //预处理求合法状态
    for(int i = 0; i < 1 << m; ++ i)//模拟所有状态
        if(check(i))//检查状态是否合法
        {
            //保存信息
            st.push_back(i);
        }
    
    //预处理合法状态的合法连接
    for(int i = 0; i < st.size(); ++ i)
        for(int j = 0; j < st.size(); ++ j)
        {
            int a = st[i], b = st[j];
            
            if((a & b) == 0)
                head[i].push_back(j);//对应的都是下标
        }
    
    f[0][0] = 1;
    for(int i = 1; i <= n + 1; ++ i)
        for(int a = 0; a < st.size(); ++ a)
            if((st[a] & h[i]) == 0)//状态为st[a]，不能有种在贫瘠土地上的情况, == 高于 &
                for(auto b : head[a])
                {
                    //a，b都是下标
                        f[i][st[a]] = (f[i][st[a]] + f[i - 1][st[b]]) % MOD;
                }
    
    // int res = 0;
    // for(int i = 0; i < st.size(); ++ i)
    //     res += f[n][st[i]];
    // cout << res << endl;
    cout << f[n + 1][0];
    
    return 0;
}
