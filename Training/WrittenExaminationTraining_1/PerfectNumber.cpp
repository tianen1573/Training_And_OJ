// ��ȫ��(Perfect number)���ֳ����������걸������һЩ�������Ȼ����
// �����е�������(���������������Լ��)�ĺ�(�����Ӻ���)��ǡ�õ���������
// ����:28������Լ��1��2��4��7��14��28����ȥ������28�⣬����5������ӣ�1+2+4+7+14=28��
// ����n�������n����(��n)��ȫ���ĸ�����
// ���ݷ�Χ:1��n ��5�� 105


#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    
    int cnt = 0;
    
    for(int i = 6; i <= n; ++ i)
    {
        int sum = 1;
        for(int j = 2; j <= sqrt(i); ++ j)
        {
            int ij = i / j;
            if(i % j == 0)
            {
                sum += j;
                sum += ij;
                if(sum > i)
                {
                    break;
                }
            }
        }
        if(sum == i)
        {
            cnt ++;
        }
        
        
    }
    cout << cnt;
    return 0;
}