class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        int n = s1.size(), m = s2.size();
        if(n + m != s3.size()) return false;


        // f[i][j]：s1的前i个，s2的前j个，能否构成s3的前i+j个
        // 滚动数组优化
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1, false));
        f[0][0] = true;

        // 若第i个元素，与第i+j个元素相等，则判断f[i - 1][j]是否可行
        // j，亦然
        for(int i = 0; i <= n; ++ i)
            for(int j = 0; j <= m; ++ j)
            {
                int p = i + j - 1;

                if(i > 0)
                    f[i][j] = ((s1[i - 1] == s3[p]) && f[i - 1][j]);
                if(j > 0 && ((s2[j - 1] == s3[p]) && f[i][j - 1]))
                    f[i][j] = true; 
            }
        return f[n][m];

    }
};