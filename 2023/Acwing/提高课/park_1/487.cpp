//分组背包 + 模拟状态
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> PII;

const int N = 67, M = 32010;

PII master[N];//存储主件
vector<PII> son[N];//存储主件i对应的所有附件
int f[M];

int n, m;

int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> m >> n;
    
    for(int i = 1; i <= n; ++ i)
    {
        int v, p, s; cin >> v >> p >> s;
        p *= v;
        
        if(s == 0) master[i] = {v, p};//主件
        else son[s].push_back({v, p});//附件
    }
    
    PII nul = {0,0};//非主件状态
    for(int i = 1; i <= n; ++ i)//1. 先种类
    {
        if(master[i] == nul)  continue;//不是主件，直接跳过
        
        for(int j = m; j >= 0; -- j)//2. 再空间
            for(int k = 0; k <= 1 << son[i].size(); ++ k)//3. 最后物品
            {
                //第i个主件，我们用主件+附件构建一个分组背包问题
                //k用来模拟 选择附件的 状态，如00，01，10，11，代表都不选，选第一个，选第二个，俩都选
                int v = master[i].first, w = master[i].second;//必须选主件
                
                for(int u = 0; u < son[i].size(); ++ u)//构建k状态时，对应的体积和价值
                    if(k >> u & 1)
                    {
                        v += son[i][u].first;
                        w += son[i][u].second;
                    }
                
                if(j >= v) f[j] = max(f[j], f[j - v] + w);//更新
            }
    }
    
    cout << f[m];
    
    
    return 0;
}