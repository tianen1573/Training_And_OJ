// 某商店规定:三个空汽水瓶可以换一瓶汽水，允许向老板借空汽水瓶(但是必须要归还)。
// 小张手上有n个空汽水瓶，她想知道自己最多可以喝到多少瓶汽水。

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