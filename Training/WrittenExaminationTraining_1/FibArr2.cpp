// ��һ�����ӣ��ӳ������3������ÿ���¶���һֻ���ӣ�С���ӳ����������º�ÿ��������һֻ���ӡ�
// ����:����һֻ���ӵ�3���³�������ô����5���¿�ʼ��ÿ������һֻ���ӡ�
// һ�µ�ʱ����һֻ���ӣ��������Ӷ��������ʵ�n���µ���������Ϊ����?
#include<iostream>
using namespace std;

int main()
{
    int prePre = 1, pre = 1, cur = 0;
    int n = 0;
    cin >> n;
    for(int i = 2; i < n; ++ i)
    {
        cur = pre + prePre;
        prePre = pre;
        pre = cur;
    }
    
    cout << cur;
    
    return 0;
}
