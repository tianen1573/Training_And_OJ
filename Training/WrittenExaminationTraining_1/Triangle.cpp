//三角形
//https://www.nowcoder.com/questionTerminal/c67a09062c0f4a5b964eef0945d3dd06
#include<iostream>
using namespace std;

//大数加法
int main()
{
    double a, b, c;
    
    while(cin >> a >> b >> c)
    {
        double _min = min(a, min(b, c));
        double _max = max(a, max(b, c));
        double _mid = a + b + c - _min - _max;

        if(_min + _mid > _max)
            cout << "Yes";
        else
            cout << "No";
        
        cout << endl;
    }
    
    return 0;
}