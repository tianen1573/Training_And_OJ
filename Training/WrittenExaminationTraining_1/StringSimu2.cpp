
// 输入描述:
// 输入第一行为字符串个数n (n ≤ 100)
// 接下来的n行,每行一个字符串,字符串长度均小于100，均由小写字母组成
// 输出描述:
// 如果这些字符串是根据字典序排列而不是根据长度排列输出"lexicographically"，
// 如果根据长度排列而不是字典序排列输出"lengths" ,
// 如果两种方式都符合输出"both"，否则输出"none"

#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    
    bool isLen = true, isDir = true;
    string a, b;
    
    
    --n;
    cin >> a;
    
    while(n > 0)
    {
        cin >> b;
        if( b.size() < a.size())
        {
            isLen = false;
        }
        if(b < a)
        {
            isDir = false;
        }
        
        a = b;
        --n;
    }
    
    if(isLen && isDir)
    {
        cout << "both";
    }
    else if(isLen && !isDir)
    {
        cout << "lengths";
    }
    else if(!isLen && isDir)
    {
        cout << "lexicographically";
    }
    else
    {
        cout << "none";   
    }
    
    return 0;
}

最小公倍数
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