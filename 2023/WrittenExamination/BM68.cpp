class Solution {
public:

    int minPathSum(vector<vector<int> >& matrix) {
        int f[511][511];
        memset(f, 0x3f, sizeof f);
        f[0][1] = f[1][0] = 0;

        for(int i = 0; i < matrix.size(); ++ i)
            for(int j = 0; j < matrix[0].size(); ++ j)
            {
                f[i + 1][j + 1] = matrix[i][j] + min(f[i + 1][j], f[i][j + 1]);
            }
        
        return f[matrix.size()][matrix[0].size()];
    }
};