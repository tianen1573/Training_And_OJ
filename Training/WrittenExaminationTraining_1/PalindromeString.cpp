
/*“回文串”是一个正读和反读都一样的字符串，
比如"level"或者“noon"等等就是回文串。
花花非常喜欢这种拥有对称美的回文串，生日的时候她得到两个礼物分别是字符串A和字符串B。
现在她非常好奇有没有办法将字符串B插入字符串A使产生的字符串是一个回文串。
你接受花花的请求，帮助她寻找有多少种插入办法可以使新串是一个回文串。
如果字符串B插入的位置不同就考虑为不一样的办法。*/

#include<iostream>
#include<string>
using namespace std;

bool IsPalindrome(string& str)
{
    for(int i = 0, j = str.size() - 1; i < j; ++i, --j)
    {
        if(str[i] != str[j])
        {
            return false;
        }
    }
    
    return true;
}

int main()
{
    string strA, strB;
    cin >> strA >> strB;
    
    int cnt = 0;
    for(int i = 0; i <= strA.size(); ++i)
    {
        string tmp = strA.substr(0, i) + strB + strA.substr(0 + i, string::npos);
        if(IsPalindrome(tmp))
        {
            ++cnt;
        }
    }
    
    cout << cnt;
    
    return 0;
}