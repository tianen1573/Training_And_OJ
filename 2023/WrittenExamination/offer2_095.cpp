class Solution {
public:
    int longestCommonSubsequence(string A, string B) {
        
        //f[i + 1][j + 1]：A至i，B至j的最长序列

        vector<vector<int>> f(A.size() + 1, vector<int>(B.size() + 1, 0));
        
        for(int i = 0; i < A.size(); ++ i)
            for(int j = 0; j < B.size(); ++ j)
            {
                f[i + 1][j + 1] = max(f[i + 1][j], f[i][j + 1]);
                if(A[i] == B[j])
                    f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j] + 1);
            }
        
        return f[A.size()][B.size()];

    }
};