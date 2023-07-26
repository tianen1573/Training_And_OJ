class Solution {
public:
    // dp
    // 组合数
    int uniquePaths(int m, int n) {
        
        int f[101][101] = {0};
        f[0][1] = 1;

        for(int i = 1; i <= n; ++ i)
            for(int j = 1; j <= m; ++ j)
                f[i][j] = f[i - 1][j] + f[i][j - 1];
        
        return f[n][m];
    }
};