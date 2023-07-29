class Solution {
  public:

    //f[i,j,k]：第i天时，进行了j笔交易，股票状态为k(1,0)时 的 最大价值， 记买入时交易数+1
    //f[i,j,0] = max(f[i-1,j,0], f[i-1,j,1] + wi)
    //f[i,j,1] = max(f[i-1,j,1], f[i-1,j-1,0] - wi)，买入时j发生变化
    //初始化：第零/一天，j==0&&k==0时，为0
    int maxProfit(vector<int>& prices) {

        // const int N = 1e5 + 11;
        // int f[N][3][2] = {0};
        // memset(f, -0x3f, sizeof f);
        // f[0][0][0] = f[1][0][0] = 0; // 第一天只能买，不能卖
        // for(int i = 0; i < prices.size(); ++ i)
        //     for(int j = 0; j <= 2; ++ j)
        //     {
        //         //无股票
        //         f[i + 1][j][0] = max(f[i][j][0], f[i][j][1] + prices[i]);
        //         //有股票
        //         f[i + 1][j][1] = max(f[i + 1][j][1], f[i][j][1]);
        //         if(j) f[i + 1][j][1] = max(f[i + 1][j][1], f[i][j - 1][0] - prices[i]);
        //     }

        //滚动数组
        int f[2][3][2];
        memset(f, -0x3f, sizeof f);
        f[0][0][0] = f[1][0][0] = 0;
        for(int i = 0; i < prices.size(); ++ i)
        {
            for(int j = 1; j <= 2; ++ j)
            {
                f[(i + 1) & 1][j][0] = max(f[i & 1][j][0], f[i & 1][j][1] + prices[i]);
                f[(i + 1) & 1][j][1] = max(f[i & 1][j][1], f[i & 1][j - 1][0] - prices[i]);
            }
        }
        int ret = 0;
        for(int i = 0; i <= 2; ++ i)
            ret = max(ret, f[prices.size() & 1][i][0]);
        
        return ret;
    }
};