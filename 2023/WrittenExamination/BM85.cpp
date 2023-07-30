#include <cctype>
class Solution {
public:
    
    bool toInt(const string &str, bool flag)
    {
        if(str == "") return false; // 连续的控制符
        if(flag) // ipv4
        {
            //不允许前置0
            if(str[0] == '0' && str.size() > 1)
                return false;
        }
        else // ipv6 
        {
            //不允许连续前置0
            if(str[0] == '0' && str.size() > 1 && str[1] == '0')
                return false;
        }

        int val = 0;
        for(auto ch : str)
        {
            if(isdigit(ch)) // 数字
            {
                val = val * 10 + ch - '0';
            }
            else if(!flag && isalpha(ch)) // 字母：仅ipv6允许字母
            {
                ch |= 0b100000; // 转换成小写
                if(ch > 'f') return false; // v6字符越界
                val = val * 10 + ch - 'a';
            }
            else
                return false; // 非法字符
        }

        if(flag) return val < 256;
        else return val < 65536;
    }

    string solve(string IP) {
        
        bool v4 = false, v6 = false;
        if(IP.find('.') != string::npos) v4 = true;
        if(IP.find(':') != string::npos) v6 = true;

        if(v4 && v6) return "Neither"; // 只允许存在 '.' 或 ':'
        else if(v4)
        {
            int cnt = 0, start = 0;
            while(start < IP.size())
            {
                int end = IP.find('.', start); // 查找'.'
                if(end == string::npos) end = IP.size(); // 最后一个
                if(toInt(IP.substr(start, end - start), true))
                {
                    start = end + 1;
                    ++ cnt;
                }
                else
                    return "Neither";
            }
            if(cnt == 4) // 4个合法字段
            {
                if(IP[IP.size() - 1] == '.') // 如果最后一个是控制符，则直接失败
                    return "Neither";
                
                return "IPv4";
            }
                
        }
        else if(v6)
        {
            int cnt = 0, start = 0;
            while(start < IP.size())
            {
                int end = IP.find(':', start);
                if(end == string::npos) end = IP.size();
                if(toInt(IP.substr(start, end - start), false))
                {
                    start = end + 1;
                    ++ cnt;
                }
                else
                    return "Neither";
            }
            if(cnt == 8)
            {
                if(IP[IP.size() - 1] == ':') // 如果最后一个是控制符，则直接失败
                    return "Neither";
                
                return "IPv6";
            }
        }

        return "Neither";
    }
};