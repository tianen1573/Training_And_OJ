
// 最小公倍数

#include<iostream>

using namespace std;

int gcd(int a, int b)
{
    if(a < b)
    {
        return gcd(b, a);
    }
    else if(a % b == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, a % b);   
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    
    cout << a * b / gcd(a, b);
    
    return 0;
}