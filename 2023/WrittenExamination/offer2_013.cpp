class NumMatrix {
public:

    int pre[211][211] = {0};

    NumMatrix(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); ++ i)
            for(int j = 0; j < matrix[0].size(); ++ j)
            {
                pre[i + 1][j + 1] = matrix[i][j] + pre[i - 1 + 1][j + 1] + pre[i + 1][j - 1 + 1] - pre[i - 1 + 1][j - 1 + 1];
            }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {

        int sum = pre[row2 + 1][col2 + 1] - pre[row1][col2 + 1] - pre[row2 + 1][col1] + pre[row1][col1];
        return sum;
    }
};
