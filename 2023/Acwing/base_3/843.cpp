#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 11;

char g[N][N];
//列，对角线，反对角线 : 对应的某条线，是否存在皇后
//某行上唯一存在皇后，我们通过遍历来控制
//某列上存在唯一皇后，我们通过c[]控制，下标即代表列数
//而正反两个对角线，我们通过截距控制，可知，截距的大小最大为n的2倍
char c[N], dg[N * 2], udg[N * 2];
int n;

void dfs(int k)//第k个皇后，并且放在第k行
{
    //行列，确定某一个皇后的问题，我们默认第k个皇后，放在第k行
    //则需要遍历列数，判断皇后是否可以放在某列
    if(k > n)
    {
        for(int i = 1; i <= n; ++ i)
            cout << g[i] + 1 << endl;
        
        cout << endl;
        
        return ;
    }
    
    for(int j = 1; j <= n; ++ j)
    {
        if(c[j] || dg[k + j] || udg[k - j + n]) continue;//某条线上存在皇后
        
        c[j] = dg[k + j] = udg[k - j + n] = true;
        g[k][j] = 'Q';
        dfs(k + 1);
        //恢复现场
        c[j] = dg[k + j] = udg[k - j + n] = false;
        g[k][j] = '.';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); 
    std::cout.tie(0);
    
    cin >> n;
    
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= n; ++ j)
            g[i][j] = '.';
    
    dfs(1);
    
    return 0;
}