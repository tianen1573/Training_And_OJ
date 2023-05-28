//markdown文档
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 12, M = 1 << 10, K = 111;

long long f[N][K][M];//f[i][j][k],前i行已经放好，已经摆放了j个国王，且第i行的状态为k时 的 方案数

//状态压缩基础数据结构
vector<int> st;//保存合法状态
vector<int> head[M];//保存合法状态 的 合法联通； 如第i行状态为a， 所有的合法i-1行状态b 都放进集合
//其他
int cnt[M];//保存状态为a时， 存在几个国王

int n, m;

bool check(int state)
{
    for(int i = 0; i < n; ++ i)
        // if((state >> i & 1) && (state >> (i + 1) & 1))//存在连续1
        if(state & (state >> 1))
            return false;
    
    return true;
}

int count(int state)
{
    int cnt = 0;
    
    for(int i = 0; i < n; ++ i)
        if(state >> i & 1)
            ++ cnt;
            
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    //预处理求合法状态
    for(int i = 0; i < 1 << n; ++ i)//模拟所有状态
        if(check(i))//检查状态是否合法
        {
            //保存信息
            st.push_back(i);
            cnt[i] = count(i);
        }
    
    //预处理合法状态的合法连接
    for(int i = 0; i < st.size(); ++ i)
        for(int j = 0; j < st.size(); ++ j)
        {
            int a = st[i], b = st[j];
            
            if((a & b) == 0 && check(a|b))
                head[i].push_back(j);//对应的都是下标
        }
    
    f[0][0][0] = 1;
    for(int i = 1; i <= n + 1; ++ i)
        for(int j = 0; j <= m; ++ j)
            for(int a = 0; a < st.size(); ++ a)
                for(auto b : head[a])
                {
                    //a，b都是下标
                    int c = cnt[st[a]];
                    if(j >= c)
                        f[i][j][st[a]] += f[i - 1][j - c][st[b]];
                }
    
    // int res = 0;
    // for(int i = 0; i < st.size(); ++ i)
    //     res += f[n][m][st[i]];
    // cout << res << endl;
    cout << f[n + 1][m][0];
    
    return 0;
}
