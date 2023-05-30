#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1511;

int h[N], e[N], ne[N], idx;
int st[N];

int f[N][2];//转移关系看md

int n;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u)
{

    f[u][0] = 0, f[u][1] = 1;
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        dfs(j);

        f[u][0] += f[j][1];
        f[u][1] += min(f[j][1], f[j][0]);
    }
}

int main()
{
    while(cin >> n)
    {
        memset(h, -1, sizeof h);
        idx = 1;
        memset(st, 0, sizeof st);

        while(n -- )
        {
            int pre, cnt;
            scanf("%d:(%d)", &pre, &cnt);

            //构建有向图
            while(cnt --)
            {
                int son; cin >> son;
                add(pre, son);
                st[son] = true;
            }
        }

        //有向图需要找根
        int root = 0;
        while(st[root]) ++ root;

        dfs(root);
        cout << min(f[root][0], f[root][1]) << endl;

    }

    return 0;
}
