// 问题描述:在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、i正则表达式等领域。现要求各位实现字符串通配符的算法。
// 要求:
// 实现如下2个通配符:
// *:儿配O个或以上的字符(注:能被*和?匹配的字符仅由英文字母和数字0到9组成，下同)
// ?∶匹配1个字符
// 注意:匹配时不区分大小写。
#include <iostream>
#include <string>
using namespace std;
// https://www.nowcoder.com/practice/43072d50a6eb44d2a6c816a283b02036
bool match(const char* pattern, const char *str)
{
    if (*pattern == '\0' && *str == '\0')    //当前字符结束，返回true
    {
        return true;
    }
    if (*pattern == '\0' || *str == '\0')    //两个字符串有一个先结束，则返回false
    {
        return false;
    }
    
    if (*pattern == '?')   //遇到?号，匹配一个字符，跳过第一个位置
    {  
        if(!isalnum(*str)) //仅匹配字母和数字
        {
            return false;
        }
        return match(pattern + 1, str + 1);
    }
    else if (*pattern == '*')
    {
        //合并*
        int cnt = 1;
        while(*(pattern + cnt) == '*')
        {
            cnt++;
        }
        --cnt;
        // 遇到*号，匹配0个(str不挪动)，1个（两者都向前挪动一个字符）或多个(str向前挪动一个字符)
        return match(pattern + cnt + 1, str) 
            || match(pattern + cnt + 1, str + 1) 
            || match(pattern, str + 1);
    }
    else if (*pattern == *str)//如果当前字符相等，匹配下一个字符
    {    
        return match(pattern + 1, str + 1);
    }
    return false;
}
int main(){
    string pattern, str;    //pattern样式字符串、str实际字符串
    while (cin >> pattern >> str){
        //转换成小写
        for(auto& x : pattern)
        {
            if(x >= 'A' && x <= 'Z')
            {
                x += 32;
            }
        }
        for(auto& x : str)
        {
            if(x >= 'A' && x <= 'Z')
            {
                x += 32;
            }
        }
        
        bool ret = match(pattern.c_str(), str.c_str());
        if (ret)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}