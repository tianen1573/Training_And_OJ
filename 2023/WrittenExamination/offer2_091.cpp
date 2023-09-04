class Solution {
public:
    int minCost(vector<vector<int>>& costs) {

        int len = costs.size();
        for(int i = 1; i < len; ++ i)
        {
            for(int j = 0; j < 3; ++ j)
                costs[i][j] += min(costs[i - 1][(j + 1) % 3], costs[i - 1][(j + 2) % 3]);
        }

        int ret = min( min(costs[len - 1][0], costs[len - 1][1]), costs[len - 1][2]);
        return ret;
    }
};