
// 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。
// 数值为О或者字符串不是一个合法的数值则返回0
// 数据范围:字符串长度满足0<n ≤100
// 进阶:空间复杂度O(1)，时间复杂度O(n)


class Solution {
public: 
    int StrToInt(string str) {
        
        if(str == "" || str == "0")
        {
            return 0;
        }
        
        int res = 0;
        int flag = 1;
        int i = 0;
        
        if(str[0] == '-' || str[0] == '+')
        {
            flag = str[0] == '-' ? -1 : 1;
            ++i;
        }
        
        while(i < str.size())
        {
            if(str[i] < '0' || str[i] > '9')
            {
                return 0;
            }
            res = res * 10 + str[i] - '0';
            ++i;
        }
        
        res *= flag;
        
        return res;
        
    }
};