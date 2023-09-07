class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        typedef pair<int, int> XY;
        queue<XY> que;

        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));

        int xy[5] = {0, 1, 0, -1, 0};
        int d = 0;

        for(int i = 0; i < n; ++ i)
            for(int j = 0; j < m; ++ j)
            {
                if(mat[i][j] == 0)
                {
                    dist[i][j] = 0;
                    que.push({i, j});
                }
            }
        // 为了避免元素被重复放入队列
        // 1. 辅助数组，标记元素是否已经求得距离
        // 2. 用距离数组来标识
        while(que.size())
        {
            int len = que.size();
            for(int i = 0; i < len; ++ i)
            {
                auto [x, y] = que.front();
                que.pop();

                for(int j = 0; j < 4; ++ j)
                {
                    int nx = x + xy[j];
                    int ny = y + xy[j + 1];
                    // 不越界，没有确定距离
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m || dist[nx][ny] != -1)
                        continue;
                    
                    dist[nx][ny] = d + 1;
                    que.push({nx, ny});
                }
            }

            ++ d;
        }

        return dist;
    }
};