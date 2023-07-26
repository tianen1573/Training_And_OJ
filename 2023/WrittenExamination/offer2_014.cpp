class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // s1的全排列是否是s2的字串 ->> s1的字符集是否和s2字串的字符集相同
        // 1. 前缀和数组统计a~z的个数，求差分是否和s1的相同
        // 2. 开滑，优化方案是记录 个数不同的字符的个数(diff)， 不再比较数组，比较diff是否为0
        // 开滑
        if(s2.size() < s1.size()) return false;

        //先统计str1的字符集
        int cnt[26] = {0}, diff = 0, len = s1.size();
        for(auto ch : s1)
            ++ cnt[ch - 'a'];
        //把窗口枝棱起来
        int i = 0;
        for(; i < s1.size(); ++ i)
            -- cnt[s2[i] - 'a'];
        //统计个数差非0的字符
        for(auto val : cnt)
            if(val) ++ diff;
        if(diff == 0) return true;
        //开滑
        for(; i < s2.size(); ++ i)
        {
            if(s2[i] == s2[i - len]) continue;
                
            if(cnt[s2[i - len] - 'a'] == -1) -- diff; // 多了一个零
            else if(cnt[s2[i - len] - 'a'] == 0) ++ diff;// 少了一个零
            ++ cnt[s2[i - len] - 'a'];
            if(cnt[s2[i] - 'a'] == 1) -- diff; // 多了一个零
            else if(cnt[s2[i] - 'a'] == 0) ++ diff; // 少了一个零
            -- cnt[s2[i] - 'a'];

            if(diff == 0) return true;
        }
        return false;
    }
};