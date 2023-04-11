class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {

        int maxP = grid[0][0];
        for(int i = 1; i < grid[0].size(); ++ i)
        {
            grid[0][i] += grid[0][i - 1];
            maxP = max(maxP, grid[0][i]);
        }
        for(int i = 1; i < grid.size(); ++ i)
        {
            grid[i][0] += grid[i - 1][0];
            maxP = max(maxP, grid[i][0]);
        }


        for(int i = 1; i < grid.size(); ++ i)
            for(int j = 1; j < grid[0].size(); ++ j)
            {
             grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
             maxP = max(maxP, grid[i][j]);
            }

        return maxP;
        

    }
};