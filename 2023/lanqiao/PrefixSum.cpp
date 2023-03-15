/*
将数组分为三部分，那么确定其中的两个部分，第三个部分就是确定的，则转化为确定数组的前两部分
前两部分有着明确的枢值，第一个为sum/3，第二个为sum/3*2
确定第一枢值，找后面有几个第二枢值
避免全排列，找枢值使用前缀和，找几个使用后缀和
*/


#include<iostream>

using namespace std;

const int N = 1e5 + 11;
int sum[N];
int cnt[N];
int main()
{
    int n = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i) 
    {
        scanf("%d", &sum[i]);
        sum[i] += sum[i - 1];
    }
    
    long long ans = 0;
    int flag = sum[n] / 3, flag_2 = flag * 2;
    if(flag * 3 != sum[n] || n < 3)
    {
        printf("0");
        return 0;
    }
    
    for(int i = n - 1; i > 1; i --)
    {
        cnt[i] = cnt[i + 1];
        if(sum[i] == flag_2)
            cnt[i]++;
    }
    
    for(int i = 1; i < n; ++ i)
    {
        if(sum[i] == flag)
            ans += cnt[i + 1];
    }
    
    
    printf("%ld", ans);

    
    return 0;
}