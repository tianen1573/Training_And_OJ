#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

const int N = 100010;

int p[N], cnt[N];

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);//路径压缩 -- 递归
    
    return p[x];
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i) p[i] = i, cnt[i] = 1;
    
    while(m --)
    {
        string op;
        int a, b;
        cin >> op;
        
        if(op == "C")
        {
            scanf("%d%d", &a, &b);
            
            a = find(a), b = find(b);//若没有路径压缩，可减少递归次数
            if(a == b) continue;//注意和上条语句的顺序， 如果在同一个连通块，直接跳过
            
            cnt[b] += cnt[a];//注意这两条语句的顺序
            p[a] = b;
        }
        else if(op == "Q1")
        {
            scanf("%d%d", &a, &b);
            if(find(a) == find(b)) printf("Yes\n");
            else printf("No\n");
        }
        else
        {
            scanf("%d", &a);
            printf("%d\n", cnt[find(a)]);
        }
    }
    
    return 0;
}