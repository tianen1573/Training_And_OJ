

// Fibonacci���������������:F[0]=0
// F[1]=1
// for each i�� 2:F[i]=F[ i-1]+F[i-2]
// ��ˣ�Fibonacci���о�����:0��1��1,2,3��5,8,13,...����Fibonacci�����е������ǳ�ΪFibonacci����
// ����һ��N�����������Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX-1����X+1��
// ���ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci����


#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    
    int a = 1, b = 1, c = 2;
    int cnt = n - 1;
    
    while(c <= n)
    {
        //�ж�-
        cnt = n - c;
        
        c = a + b;
        a = b;
        b = c;
    }
    
    //�ж�+
    cnt = min(cnt, c - n);
    
    cout << cnt;
    
    return 0;
}
