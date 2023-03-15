#include <iostream>
#include <cstdio>
#include<cstring>


using namespace std;

int sub[200007];
int n;

void insert(int l, int r)
{
    sub[l] += 1;
    sub[r + 1] -= 1;
}

int main()
{
    int t = 0; scanf("%d", &t);
    while(t--)
    {
        scanf("%d", & n);
        int num;
        memset(sub, 0, sizeof sub);
        for(int i = 1; i <= n; ++ i)
        {
            scanf("%d", &num);
            int r = i;
            int l = max(1, i - num + 1);
            if(r >=l) insert(l, r);
        }
        
        int val = 0;
        for(int i = 1; i <= n; i ++)
        {
            val += sub[i];
            //printf("%d ", val);
            //val += sub[i];
            if(val) printf("1 ");
            else printf("0 ");
        }
        printf("\n");
        
    }
    
    
    return 0;
}