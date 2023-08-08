class Solution {
public:

    // 1. 把第一列变成第一行
    // 2. 按正对角线翻转，再按竖中线翻转
    vector<vector<int> > rotateMatrix(vector<vector<int> >& mat, int n) {
        
        for(int i = 0; i < n; ++ i)
        {
            for(int j = i + 1; j < n; ++ j)
            {
                swap(mat[i][j], mat[j][i]);
            }
        }
        for(int i = 0; i < n; ++ i)
        {
            int l = 0, r = n - 1;
            while(l < r)
            {
                swap(mat[i][l++], mat[i][r--]);
            }
        }

        return mat;
    }
};