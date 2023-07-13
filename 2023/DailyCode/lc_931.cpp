class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& g) {

        int n = g.size();
        for(int i = 1; i < n; ++ i)
            for(int j = 0; j < n; ++ j)
            {
                int l = max(0, j - 1);
                int m = j;
                int r = min(n - 1, j + 1);
                g[i][j] += min(g[i - 1][l], min(g[i - 1][m], g[i - 1][r]));
            }
        int res = INT_MAX;
        for(int i = 0; i < n; ++ i)
            res = min(res, g[n - 1][i]);

        return res;
    }
};