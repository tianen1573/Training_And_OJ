// 完全数(Perfect number)，又称完美数或完备数，是一些特殊的自然数。
// 它所有的真因子(即除了自身以外的约数)的和(即因子函数)，恰好等于它本身。
// 例如:28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1+2+4+7+14=28。
// 输入n，请输出n以内(含n)完全数的个数。
// 数据范围:1≤n ≤5× 105


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