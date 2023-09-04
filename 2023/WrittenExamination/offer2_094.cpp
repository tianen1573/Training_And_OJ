class Solution {
private:
    string str;
public:

    bool isPlalindrome(int l, int r)
    {
        while(l < r)
        {
            if(str[l] != str[r])
                return false;
            
            ++ l;
            -- r;
        }

        return true;
    }
    /*
    for (int i = n - 1; i >= 0; --i) 
    {
        for (int j = i + 1; j < n; ++j) {
            g[i][j] = (s[i] == s[j]) && g[i + 1][j - 1];
        }
    }
    */
    int minCut(string s) {

        this->str = s;
        // f[i + 1]：使得0~i满足条件的最小切割次数
        // f[i + 1]：由前面转移而来
        vector<int> f(s.size() + 1, 0x3f3f3f3f);
        f[0] = -1;
        for(int i = 0; i < s.size(); ++ i)
        {
            for(int j = 0; j <= i; ++ j)
            {
                // 如果j~i是回文串，则需要知道f[j - 1 + 1] 的值
                // 即以0~j-1的最小次数
                if(isPlalindrome(j, i))
                    f[i + 1] = min(f[j] + 1, f[i + 1]);
                    //f[i + 1] = min(f[j - 1 + 1] + 1, f[i + 1]);
            }
        }
        return f[s.size()];
    }
};