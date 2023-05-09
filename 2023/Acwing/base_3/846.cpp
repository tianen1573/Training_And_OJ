#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 100011;

int h[N], e[N * 2], ne[N * 2], idx;//注意边的数量

int n, res = 0x3f3f3f3f;
bool st[N];

void add(int k, int val)
{
    e[idx] = val;
    ne[idx] = h[k];
    h[k] = idx;
    ++ idx;
}

/*
通过递归dfs，从下到上求节点个数
则一个节点被删除时，可分为n+1个连通块，n是其子节点个数
子树所在的连通块通过递归获取，而非子树的连通块只有一个，即其父节点所在的连通块
而且这个连通块的结点数苛求：n-sum-1
先求该节点删除时的最大结点数，再求所有情况下的最小结点数
*/
int dfs(int u)
{
    st[u] = true;
    
    //size：删除该节点时，得到的最大连通块结点数
    int size = 0, sum = 0;
    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];//取节点值
        if(st[j]) continue;//遍历过
        
        int t = dfs(j);//递归求子树的连通块节点数
        sum += t;//该节点为根节点时的连通块节点数，算上子树
        size = max(size, t);
    }
    
    size = max(size, n - sum - 1);//去掉子树，去掉自己，其他节点一定是一个连通块
    res = min(res, size);
    
    return sum + 1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    memset(h, -1, sizeof h);//将桶初始为空，sizeof + 变量名， 不需要加(), 数据类型需要()
    
    cin >> n;
    
    for(int i = 0; i < n - 1; ++ i)
    {
        int a, b; cin >> a >> b;
        add(a, b), add(b, a);
    }
    
    dfs(1);
    
    cout << res;
    
    return 0;
}