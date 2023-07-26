class Solution {
public:
    
    // f[i][j]：分别以a[i],b[j]结尾的串 的LCS长度
    // [i] != [j], f[i][j] = 0;
    // [i] == [j], f[i][j] = f[i - 1][j - 1] + 1
    string LCS(string str1, string str2) {
        
        int n = str1.size(), m = str2.size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
        int pos = 0, maxLen = 0;

        for(int i = 0; i < n; ++ i)
            for(int j = 0; j < m; ++ j)
            {
                if(str1[i] == str2[j])
                {
                    f[i + 1][j + 1] = f[i][j] + 1;
                    if(f[i + 1][j + 1] > maxLen)
                    {
                        maxLen = f[i + 1][j + 1];
                        pos = i;
                    }
                }
            }
        
        string res = str1.substr(pos - maxLen + 1, maxLen);
        return res;
    }
};