/*
�������Ϊ�����֣���ôȷ�����е��������֣����������־���ȷ���ģ���ת��Ϊȷ�������ǰ������
ǰ������������ȷ����ֵ����һ��Ϊsum/3���ڶ���Ϊsum/3*2
ȷ����һ��ֵ���Һ����м����ڶ���ֵ
����ȫ���У�����ֵʹ��ǰ׺�ͣ��Ҽ���ʹ�ú�׺��
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