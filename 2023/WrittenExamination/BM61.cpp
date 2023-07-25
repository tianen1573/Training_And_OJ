class Solution {
public:
    
    int res = 0;
    bool st[1011][1011] = {0};
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

    void dfs(int row, int col, int len, vector<vector<int> >& matrix)
    {
        res = max(res, len);
        
        for(int i = 0; i < 4; ++ i)
        {
            int x = row + dx[i];
            int y = col + dy[i];
            if(x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size())
                continue ;
            if(st[x][y] || matrix[x][y] <= matrix[row][col])
                continue;
            
            st[x][y] = true;
            dfs(x, y, len + 1, matrix);
            st[x][y] = false;
        }
        
        return ;
    }
    
    int solve(vector<vector<int> >& matrix) {
        
        for(int i = 0; i < matrix.size(); ++ i)
            for(int j = 0; j < matrix[0].size(); ++ j)
            {
                st[i][j] = true;
                dfs(i, j, 1, matrix);
                st[i][j] = false;
            }
        
        return res;
    }
};