
/*
差分解决一段区域同时增加或减少的问题
给区间【L，R】上都加上一个常数c，则b[L] += c , b[R + 1] -=c

求出a的差分序列b，其中b1 = a1,b(i) = a(i) - a(i - 1) (2 <= i <= n)。令b(n + 1) = 0，
题目对序列a的操作，相当于每次可以选出b1,b2…b(n + 1)中的任意两个数，一个加1，另外一个减一。目标是把b2,b3,…bn变为全0。最终得到的数列a就是由 n 个 b1 构成的

任选两个数的方法可分为四类
1、2 <= i , j <=n（优先）
2、i = 1, 2 <=j <=n
3、2 <= i <= n , j = n + 1
4、i = 1, j = n + 1（没有意义）

设b2,b3....bn中正数总和为p，负数总和的绝对值为q。首先以正负数匹配的方式尽量执行1类操作，
可执行min(p,q)次。剩余|p - q|个为匹对，每个可以选与b1或b(n + 1)匹配，即执行2 或 3 类操作，共需|p - q|次

综上所诉，最少操作次数为min(p,q) + |p - q|。根据|p - q|次第2、3类操作的选择情况，
能产生|p - q| + 1中不同的b1的值，即最终得到的序列a可能有|p - q| + 1 种

作者：小呆呆
链接：https://www.acwing.com/solution/content/5060/
*/

#include<cstdio>
#include<math.h>
#include<algorithm>
typedef long long LL;

const int N = 100011;
int a[N];

int main()
{
    int n; scanf("%d", &n);
    int tmp;
    LL q = 0, p = 0;
    for(int i = 1; i <= n; ++ i)
    {
        scanf("%d", &tmp);
        a[i] += tmp;
        a[i + 1] -= tmp;
        
        if(a[i] > 0) q += a[i];
        else p -= a[i];
    }
    q -= a[1];
    
    LL op = std::max(p, q);
    LL ans = abs(p - q) + 1;
    
    printf("%ld\n%ld", op, ans);
    
    return 0;
}