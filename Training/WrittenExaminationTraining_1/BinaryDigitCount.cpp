// ��һ��int�������ֶ�Ӧ�Ķ�����������1�����������������3�Ķ�����Ϊ00000011���������2��1
// ���ݷ�Χ:��������: 1<t��5��1 <n ��500000����:ʱ�临�Ӷ�:O(logn)���ռ临�Ӷ�:O(1)
#include<iostream>
using namespace std;

int main()
{
    int num = 0;
    cin >> num;
    
    int res = 0, cnt = 0;
    
    for(int i = 0; i < 32; ++i)
    {
        if(num >> i & 1)
        {
            ++cnt;
        }
        else
        {
            res = max(res, cnt);
            cnt = 0;
        }
    }
    
    cout << res;
    
    return 0;
}