class Solution {
public:
    int maxArea = 0;
    int n, m;
    int xy[5] = {0, 1, 0, -1, 0};
    void dfs(vector<vector<int>>& grid, int x, int y, int& area)
    {

        grid[x][y] = 0;

        bool flag = true;
        for(int i = 0; i < 4; ++ i)
        {
            int nx = x + xy[i];
            int ny = y + xy[i + 1];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == 0)
                continue;
            else
            {
                flag = false;
                area += 1;
                dfs(grid, nx, ny, area);
            }
        }

        if(flag)
            maxArea = max(maxArea, area);
        
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();
        
        for(int i = 0; i < n; ++ i)
            for(int j = 0; j < m; ++ j)
            {
                int area = 1;
                if(grid[i][j] == 1)
                    dfs(grid, i, j, area);
            }
                
        
        return maxArea;

    }
};

// class Solution {
// public:
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         int ans = 0;
//         for (int i = 0; i != grid.size(); ++i) {
//             for (int j = 0; j != grid[0].size(); ++j) {
//                 int cur = 0;
//                 stack<int> stacki;
//                 stack<int> stackj;
//                 stacki.push(i);
//                 stackj.push(j);
//                 while (!stacki.empty()) {
//                     int cur_i = stacki.top(), cur_j = stackj.top();
//                     stacki.pop();
//                     stackj.pop();
//                     if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1) {
//                         continue;
//                     }
//                     ++cur;
//                     grid[cur_i][cur_j] = 0;
//                     int di[4] = {0, 0, 1, -1};
//                     int dj[4] = {1, -1, 0, 0};
//                     for (int index = 0; index != 4; ++index) {
//                         int next_i = cur_i + di[index], next_j = cur_j + dj[index];
//                         stacki.push(next_i);
//                         stackj.push(next_j);
//                     }
//                 }
//                 ans = max(ans, cur);
//             }
//         }
//         return ans;
//     }
// };
