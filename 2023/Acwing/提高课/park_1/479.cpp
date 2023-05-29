#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 31;

//f[i][j]: 按照 从i节点到j节点中序 构成的树 的 所有最大值
int f[N][N];
int g[N][N];//g[i][j]：按照 从i节点到j节点中序 构成的树 的 所有最大值 方案的 树的根节点

int h[N];
int n;

void dfs(int l, int r)
{
    if(l > r) return ;
    
    int k = g[l][r];
    
    cout << k << ' ';
    dfs(l, k - 1);
    dfs(k + 1, r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; ++ i) cin >> h[i];
    
    for(int len = 1; len <= n; ++ len)//模拟树的节点个数
        for(int i = 1; i + len - 1 <= n; ++ i)//构建子树
        {
            int l = i, r = i + len - 1;//确定节点，[l,r]且是中序
            if(len == 1) f[l][r] = h[l], g[l][r] = l;
            else
            {
                for(int k = l; k <= r; ++ k)//模拟树的根节点
                {
                    //按照题干描述，子树为空时，其值为1
                    int left = k == l ? 1 : f[l][k - 1];
                    int right = k == r ? 1 : f[k + 1][r];
                    
                    //中序遍历为 l到r，以k为根节点的 树的值
                    int sc = left * right + h[k];
                    
                    if(f[l][r] < sc)//字典序最小的方案
                    {
                        f[l][r] = sc;
                        g[l][r] = k;
                    }
                }
            }
        }
    
    cout << f[1][n] << endl;
    dfs(1, n);//前序遍历
    
    return 0;
}
