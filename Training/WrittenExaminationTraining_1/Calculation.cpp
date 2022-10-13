
/*
A,B,C三个人是好朋友,每个人手里都有一些糖果,我们不知道他们每个人手上具体有多少个糖果,但是我们知道以下的信息:
A-B,B - C,A+B,B＋C.这四个数值.每个字母代表每个人所拥有的糖果数.
现在需要通过这四个数值计算出每个人手里有多少个糖果,即A,B,C。这里保证最多只有一组整数A,B,C满足所有题设条件。
不存在输出No
*/

#include<iostream>
using namespace std;

int main()
{
    int a_b, b_c, ab, bc;
    cin >> a_b >> b_c >> ab >> bc;
    
    int a, b, c;
    
    a = (a_b + ab) / 2;
    b = (b_c + bc) / 2;
    c = (bc - b_c) / 2;
    
    //判断是否合理
    if(a >= 0 && b >= 0 && c >= 0 
       && a * 2 == a_b + ab && b * 2 == b_c + bc && c * 2 == bc - b_c)
    {
        cout << a << ' ' << b << ' ' << c;
    }
    else
    {
        cout << "No";    
    }
    
    
    return 0;
}