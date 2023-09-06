class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        // vector<vector<int>> f(n + 1, vector<int>(amount + 1, amount + 1));
        // f[0][0] = 0;

        // for(int i = 1; i <= n; ++ i)
        // {
        //     for(int j = 0; j <= amount; ++ j)
        //     {
        //         // 当前不选
        //         f[i][j] = f[i - 1][j];
        //         // 选
        //         if(j >= coins[i - 1])
        //             f[i][j] = min(f[i][j], f[i][j - coins[i - 1]] + 1);
        //     }
        // }
        // int ret = f[n][amount] == amount + 1 ? -1 : f[n][amount];
        // return ret;

        vector<int> f(amount + 1, amount + 1);
        f[0] = 0;
        for(int i = 0; i < n; ++ i)
            for(int j = coins[i]; j <= amount; ++ j)
                f[j] = min(f[j], f[j - coins[i]] + 1);
        int ret = f[amount] == amount + 1 ? -1 : f[amount];
        return ret;
    }
};