// ĳ�̵�涨:��������ˮƿ���Ի�һƿ��ˮ���������ϰ�����ˮƿ(���Ǳ���Ҫ�黹)��
// С��������n������ˮƿ������֪���Լ������Ժȵ�����ƿ��ˮ��

#include<iostream>
using namespace std;

int main()
{
    int num = 0, res = 0;
    
    while(cin >> num)
    {
        if(num == 0)
        {
            break;
        }
        
        res = 0;
        while(num >= 3)
        {
            res += 1;
            num -= 2;
        }

        if(num == 2)
        {
            ++res;
        }

        cout << res << endl;
    }
    
    return 0;
}