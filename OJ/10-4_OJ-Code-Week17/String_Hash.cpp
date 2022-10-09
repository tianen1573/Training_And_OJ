
/*
* 输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
* 例如，输入"They are students."和"aeiou”，
* 则删除之后的第一个字符串变成"Thy r stdnts."
*/

/*
利用hash存储快速查找
*/

#include<iostream>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main()
{
    string s1, s2, res;
    unordered_set<char> hash;
    
    getline(cin, s1);
    getline(cin, s2);
    
    for(auto& x : s2)
    {
        hash.insert(x);
    }
    
    for(auto& x : s1)
    {
        if(hash.find(x) == hash.end())
        {
            res += x;
        }
    }
    
    cout << res;
    
    return 0;
}