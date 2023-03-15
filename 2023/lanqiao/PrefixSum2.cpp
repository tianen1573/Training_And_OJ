#include<stdio.h>

const int N = 1e5 + 11;
int sum[N];


int main()
{
    
    int n, m, l, r;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i)
    {
        scanf("%d", sum + i);
        sum[i] += sum[ i - 1];
    }
    
    while(m--)
    {
        scanf("%d%d", &l, &r);
        printf("%d\n", sum[r] - sum[l - 1]);
    }
    
    return 0;
}