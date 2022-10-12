
/*读入一个字符串str，输出字符串str中的连续最长的数字串*/

#include<iostream>
#include<string>

using namespace std;

bool isnum(char c)
{
    return c >='0' && c <= '9';
}

int main()
{
    string str;
    cin >> str;
    
    string res;
    int max_count = 0;
    int count = 0;
    
    for(int i = 0; i < str.size(); ++i)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            ++count;
        }
        else
        {
            if(count > max_count)
            {
                res = str.substr(i - count, count);
                max_count = count;
            }
            count = 0;
        }
    }
    
   if(count > max_count)
   {
       res = str.substr(str.size() - count, count);
       max_count = count;
   }
    
    cout << res;
    
    return 0;
}