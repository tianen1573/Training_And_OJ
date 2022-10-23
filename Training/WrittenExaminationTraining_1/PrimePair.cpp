// ����һ��ż��(����2����������2��������ɣ����ż����2�������кܶ��������
// ����ĿҪ��������ָ��ż��������������ֵ��С�������ԡ�
// ���ݷ�Χ:�������������4��n ��1000

#include<iostream>
#include<math.h>
using namespace std;

bool prime(int p)
{
    if(p == 1) return false;
	if (p == 2 || p == 3) return true; 
	if (p % 6 != 1 && p % 6 != 5) return false; 
	
	for (int i = 5; i <= floor(sqrt(p)); i += 6)
	{
		if (p % i == 0 || p % (i + 2) == 0)
			return 0;
	}
	
	return true;
}

int main()
{
    int num = 0;
    cin >> num;
    
    int _max = num / 2;//��¼�������ֵ
    int _min = 1111;//��¼��С��ֵ
    int a = 0, b = 0;//��¼��
    for(int i = 0; i <= _max; ++i)
    {
        if(prime(i) && prime(num - i))
        {
            if(num - i - i < _min)
            {
                _min = num - i - i;
                a = i;
                b = num - i;
            }
        }
            
    }
    
    cout << a << endl << b;
    
    return 0;
}