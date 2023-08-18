// https://www.nowcoder.com/exam/test/72346460/detail?pid=43184608&examPageSource=Company&testCallback=https%3A%2F%2Fwww.nowcoder.com%2Fexam%2Fcompany&testclass=%E8%BD%AF%E4%BB%B6%E5%BC%80%E5%8F%91
// 给定一个只包含小写字母字符串，每次可以选择两个相同的字符删除，
// 并在字符串结尾新增任意一个小写字母。
// 请问最少多少次操作后，所有的字母都不相同？

class Solution {
public:
    int calCnt(int n)
    {
        int cnt = 0;
        while(n > 1)
        {
            cnt += n / 2;
            n = n / 2 + n % 2;
        }
        return cnt;
    }
    int minOperations(string str) {
        // write code here
        // 统计字符个数
        int hash[26] = {0};
        for(auto ch : str)
            hash[ch - 'a']++;
        int cnt = 0, sum = 0, zero = 0;
        // 统计为0的字符个数
        for(int i = 0; i < 26; ++ i)
        {
            if(hash[i] == 0)
                ++ zero;
        }
        // 进行转换
        for(int i = 0; i < 26; ++ i)
        {
            // 大于1的才转换
            if(hash[i] > 1)
            {
                // 为2的转换成自己
                if(hash[i] == 2)
                {
                    //hash[i] = 1;
                    ++ cnt;
                }
                else
                {
                    // 优先转换成为0的字符
                    while(zero && hash[i] > 2)
                    {
                        -- zero;
                        ++ cnt;
                        hash[i] -= 2;
                    }
                    // 转换成自己
                    cnt += calCnt(hash[i]);
                }
            }
        }

        return cnt;
    }
};