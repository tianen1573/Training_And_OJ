#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 107, M = 1 << 11;

int f[2][M][M];//f[i][j][k],前i行已经布置好，且第i-1行的状态为j，第i行的状态为k时的 最大炮兵数

//状态压缩base
vector<int> st;//合法状态
vector<int> son[M];//合法状态 的 合法连接状态
//其他
int g[N];//地图状态
int cnt[M];//合法状态的炮兵数

int n, m;

bool check(int st)
{
    for(int i = 0; i < m; ++ i)
        if( (st >> i & 1) && ((st >> (i + 1) & 1)|(st >> (i + 2) & 1)) )
            return false;
    return true;
}

int count(int st)
{
    int cnt = 0;
    
    for(int i = 0; i < m; ++ i)
        if(st >> i & 1)
            ++ cnt;
        
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; ++ i)
        for(int j = 0; j < m; ++ j)
    {
        char t; cin >> t;
        g[i] |= ((t == 'H') << j);
    }
    
    for(int i = 0; i < 1 << m; ++ i)
        if(check(i))
        {
            st.push_back(i);
            cnt[i] = count(i);
        }
    for(auto a : st)
        for(auto b : st)
            if((a & b) == 0)
                son[a].push_back(b);
    
    for(int i = 1; i <= n + 2; ++ i)//枚举行
        for(auto a : st)//枚举第i行状态
            if((g[i] & a) == 0)//a不能放在山地
                for(auto b : son[a])//枚举第i-1行状态
                    if((g[i-1] & b) == 0)//b不能放在山地
                        for(auto c : son[b])//枚举第i-2行状态
                            if((a & c) == 0)
                            {
                                f[i & 1][b][a] = max(f[i & 1][b][a], f[i - 1 & 1][c][b] + cnt[a]);
                            }
    //第i行会要求i，i-1行的炮兵放置合法，和i有关联的i-2，在第i行是不再强制要求
    //由第i-1行要求，若第i-2行是违法放置，则f[i - 1 & 1][c][b] == 0
    
    cout << f[n + 2 & 1][0][0];
    
    return 0;
}