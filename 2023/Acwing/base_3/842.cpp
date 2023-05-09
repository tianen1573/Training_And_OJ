#include <cstdio>
#include <iostream>

using namespace std;

bool st[8];
int n;
int q[8];

void dfs(int k)
{
    if(k == n)
    {
        for(int i = 0; i < n; ++ i)
        {
            printf("%d ", q[i]);
        }
        printf("\n");
        
        return ;
    }
    
    for(int i = 1; i <= n; ++ i)
    {
        if(st[i]) continue;
        
        st[i] = true;
        q[k] = i;
        dfs(k + 1);
        st[i] = false;
    }
}

int main()
{
    scanf("%d", &n);

    dfs(0);
    
    return 0;
}