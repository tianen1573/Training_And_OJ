

// Fibonacci数列是这样定义的:F[0]=0
// F[1]=1
// for each i≥ 2:F[i]=F[ i-1]+F[i-2]
// 因此，Fibonacci数列就形如:0，1，1,2,3，5,8,13,...，在Fibonacci数列中的数我们称为Fibonacci数。
// 给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X-1或者X+1，
// 现在给你一个数N求最少需要多少步可以变为Fibonacci数。


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
        //判断-
        cnt = n - c;
        
        c = a + b;
        a = b;
        b = c;
    }
    
    //判断+
    cnt = min(cnt, c - n);
    
    cout << cnt;
    
    return 0;
}
