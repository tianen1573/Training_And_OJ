#include <cstdio>
#include <iostream>

using namespace std;

typedef unsigned long long ULL;
const int N = 100097, base = 131;

ULL h[N], p[N];
char str[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s", str+1);
    
    p[0] = 1, h[0] = 0;
    for(int i = 1; i <= n; ++ i)
    {
        h[i] = h[i - 1] * base + str[i];
        p[i] = p[i - 1] * base;
    }
    
    while(m --)
    {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        
        int v1 = h[r1] - h[l1 -1] * p[r1 - l1 + 1];//记住[]里的下标
        int v2 = h[r2] - h[l2 -1] * p[r2 - l2 + 1];
        
        if(v1 == v2) printf("Yes\n");//保险起见，可以再遍历一遍
        else printf("No\n");
    }
    
    return 0;
}

//个人理解
//v1 == v2, 可能不存在，取模后可能相等，概率极小
//v1 != v2, 一定不存在