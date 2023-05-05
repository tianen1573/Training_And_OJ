class Solution {
public:

    //by : https://leetcode.cn/problems/zheng-ze-biao-da-shi-pi-pei-lcof/solution/zhu-xing-xiang-xi-jiang-jie-you-qian-ru-shen-by-je/ -- Fomalhaut
    bool isMatch(string s, string p) {
        
        /*
        dp五部曲:(参考最高赞的思路)
        设原始串s的长度为m,模式串p的长度为n
        注意定义:'*'表示它前面的(一个)字符可以出现任意次（含0次）!注意是一个
        1.状态定义:设dp[i][j]为考虑s[0,i-1],p[0,j-1]时,是否能匹配上,匹配上就为true
        2.状态转移:
            2.1 p[j-1]为非'*'
                2.1.1 若p[j-1]==s[i-1](必定为'a'-'z'),继续看dp[i-1][j-1]
                2.1.2 若p[j-1]为'.',直接看dp[i-1][j-1]
            2.2 p[j-1]为'*'
                2.2.1 若p[j-2]==s[i-1](必定为'a'-'z'),则继续向前看dp[i-1][j]
                    因为对于p[0,j-1]来说,s[i-1]是冗余匹配可以由p[j-2]*补充
                2.2.2 p[j-2]为'.',则'.'匹配了s[i-1],可以继续往前看dp[i-1][j]
                    注意这里是".*"的情形,也就是"万能串",生成"......"可以匹配任何非空s
                2.2.3 此时p[j-2]为'a'-'z',且p[j-2]!=s[i-1],"p[j-2]*"直接废掉,看dp[i][j-2]
            其中2.1.1和2.1.2可以合并为一种情形;2.2.1和2.2.2可以合并为一种情形
        3.初始化:
            3.1 空的p 
                3.1.1 可以匹配空的s,dp[0][0]=true
                3.1.2 不可以匹配非空的s,dp[i][0]=false,i∈[1,m-1]
            3.2 空的s
                3.2.1 可以匹配空的s,dp[0][0]=true
                3.2.2 可能可以匹配非空的p,要经过计算如"a*b*c*"
            3.3 非空的p与非空的s,要经过计算
        4.遍历顺序:显然是正序遍历
        5.返回形式:直接返回dp[m][n]就表示考虑s[0,m-1],j[0,n-1]是否能匹配上
        */

        const int m = s.size(), n = p.size();

        vector<vector<bool>> dp(m+1, vector<bool>(n+1));

        for(int i = 0; i <= m; ++ i)
            for(int j = 0; j <= n; ++ j)
            {
                //j == 0, 即p是空串
                if(j == 0)
                {
                    dp[i][j] = i == 0;//s也是空串，才能匹配为真
                }
                else//p非空
                {
                    //dp[i][j],看的是s[i-1] == p[j-1]是否匹配
                    //p[j - 1]不是*
                    if(p[j - 1] != '*')
                    {   
                        //则s[i - 1]和p[j - 1]匹配
                        if(i >= 1 && (s[i - 1] == p[j - 1] || p[j - 1] == '.'))
                            dp[i][j] = dp[i - 1][j -1];
                    }
                    else//p[j-1]是*
                    {
                        //向前兼容
                        if(i >= 1 && j >= 2 && (s[i - 1] == p[j - 2] || p[j - 2] == '.'))
                        {
                            //p不变，s向前一位
                            dp[i][j] = dp[i - 1][j];
                        }
                        if(j >= 2)//直接忽略
                        {
                            //s不变，p向前2位
                            dp[i][j] = dp[i][j] | dp[i][j - 2];
                        }
                    }
                }
            }

            return dp[m][n];

    }
};