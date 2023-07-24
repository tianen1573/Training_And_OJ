class Solution {
public:
   
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    void dfs(int x, int y, vector<vector<char>> &g)
    {
        if(g[x][y] == '0') 
            return ;
        
        g[x][y] = '0';
        for(int i = 0; i < 4; ++ i)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx >= 0 && xx < g.size() && yy >= 0 && y < g[0].size())
                dfs(xx, yy, g);
        }

    }

    int solve(vector<vector<char> >& grid) {

        if(grid.size() == 0) return 0;

        int res = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; ++ i)
            for(int j = 0; j < m; ++ j)
            {
                if(grid[i][j] == '1')
                {
                    res ++;
                    dfs(i, j, grid);
                }
            }
        return res;
    }
};