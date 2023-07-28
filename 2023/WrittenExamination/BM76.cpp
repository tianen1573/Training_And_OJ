class Solution {
public:
    //https://leetcode.cn/problems/zheng-ze-biao-da-shi-pi-pei-lcof/

    //f[i][j]为考虑s[0,i-1],p[0,j-1]时,是否能匹配上,匹配上就为true
    bool match(string s, string p) {
        
        const int m = s.size(), n = p.size();
        int f[31][31] = {false};

        for(int i = 0; i <= m; ++ i)
            for(int j = 0; j <= n; ++ j)
            {
                
                if(j == 0)// p是空串
                {
                    f[i][j] = i == 0;
                }
                else // p非空
                {
                    //f[i][j],标记的是s[0,i-1],p[0,j-1]时,是否能匹配上
                    if(p[j - 1] != '*') // 一对一匹配
                    {
                        //s至少有一个字符
                        if(i >= 1 && s[i - 1] == p[j - 1] || p[j - 1] == '.')
                            f[i][j] = f[i - 1][j - 1];
                    }
                    else // 一对多匹配 
                    {
                        //[j]为*时，七千亩至少还有一个字符
                        if(i >= 1 && j >= 2 && (s[i - 1] == p[j - 2] || p[j - 2] == '.'))
                            f[i][j] = f[i - 1][j];//p不变，s向前一位：*变成[j-1]
                        if(j >= 2)
                            f[i][j] = f[i][j] | f[i][j - 2];//s不变，p向前两位：*把[j-1]变没
                    }
                }
            }
            return f[m][n];
    }  
};