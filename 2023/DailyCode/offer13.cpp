class Solution {
public:
    bool st[101][101] = {false};
    bool num(int row, int col, int k)
    {
        int ans = 0;

        while(row)
        {
            ans += row % 10;
            row /= 10;
        }
        while(col)
        {
            ans += col % 10;
            col /= 10;
        }

        return ans <= k;
    }
    int movingCount(int m, int n, int k) {

        queue<pair<int, int>> que;
        M = m, N = n;
        int ans = 0;

        que.push({0,0});
        st[0][0] = true;
        
        while(!que.empty())
        {
            auto [x, y] = que.front();
            que.pop();

            if(num(x, y, k))
            {
                ++ ans;
                for(int i = 0;i < 4; ++ i)
                {
                    int r = x + dec[i][0], c = y + dec[i][1];

                    if(r >= m || c >= n || r < 0 || c < 0) continue;//越界
                    if(st[r][c]) continue;//已经遍历

                    st[r][c] = true;
                    que.push({r, c});

                }
            }
        }

        return ans;

    }

    int dec[4][2] = {0,-1, -1,0, 0,1, 1,0};
    int M, N;
};