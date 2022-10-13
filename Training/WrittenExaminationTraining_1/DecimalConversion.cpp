
/*给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数*/

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int m, n;
    char arr[] = "0123456789ABCDEF";
    int sta = 1;
    
    cin >> m >> n;
    
    //判断正负
    if(m < 0)
    {
        m *= -1;
        sta = -1;
    }
    
    string res = "";
    
    while(m)
    {
        res.push_back(arr[m % n]);
        m /= n;
    }
    
    reverse(res.begin(), res.end());
    if(res == "")//判断0
    {
        res = "0";
    }    
    if(sta == -1)//判断正负
    {
        res.insert(res.begin(), '-');
    }
    
    cout << res;
    
    return 0;
}