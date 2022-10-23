// 任意一个偶数(大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，
// 本题目要求输出组成指定偶数的两个素数差值最小的素数对。
// 数据范围:输入的数据满足4≤n ≤1000

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
    
    int _max = num / 2;//记录遍历最大值
    int _min = 1111;//记录最小差值
    int a = 0, b = 0;//记录答案
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