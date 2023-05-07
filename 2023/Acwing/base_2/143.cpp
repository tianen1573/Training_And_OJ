#include <cstdio>
#include <iostream>

using namespace std;

const int N = 100010, M = 3200010;

int n;
int son[M][2], idx;

void insert(int val)
{
    int p = 0;
    for(int i = 30; i >= 0 ; -- i)//最高位为0，从次高位开始遍历
    {
        int &s = son[p][(val >> i) & 1];//使用引用，可以修改
        if(!s) s = ++ idx;
        
        p = s;
    }
}
int search(int val)
{
    int p = 0, res = 0;
    for(int i = 30; i >= 0; -- i)
    {
        int s = (val >> i) & 1;
        if(son[p][!s])//优先找与当前位相反的，且不为0时代表存在
        {
            res += (1 << i);//加
            p = son[p][!s];//向低位走
        }
        else p = son[p][s];//向地位走
    }
    
    return res;
}

int main()
{
    int val, res = 0;
    scanf("%d", &n);
    
    for(int i = 0; i < n; ++ i)
    {
        scanf("%d", &val);
        res = max(res, search(val));
        insert(val);
    }
    
    printf("%d", res);
    
    return 0;
}