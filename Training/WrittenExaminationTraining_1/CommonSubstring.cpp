// 查找两个字符串a,b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。
// 注:子串的定义:将一个字符串删去前缀和后缀（也可以不删）形成的字符串。请和“子序列"的概念分开!
// 数据范围:字符串长度1 ≤length ≤300
// 进阶:时间复杂度:O(n3)，空间复杂度:○(n)
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    
    if(b.size() > a.size())
    {
        swap(a, b);
    }
    
    //公共子串最大长度为较短的字符串的长度
    //从长到短，从左至右，依次遍历
    for(int len = b.size(); len >= 1; --len)//长到短
    {
        for(int pos_b = 0; pos_b + len - 1 < b.size(); ++pos_b)//左至右
        {
            string tmp = b.substr(pos_b, len);//记录字符串
            int pos = a.find(tmp);
            if(pos != string::npos)//存在
            {
                cout << tmp;
	      //cout << len;//输出长度
                return 0;
            }
        }
    }
    
    cout << "";
    //cout << 0;
    return 0;
}