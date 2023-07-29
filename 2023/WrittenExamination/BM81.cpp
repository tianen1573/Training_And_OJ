class Solution {
public:
    
    // 状态机：f[i+1][2]：第i天是否持有股票时的利润
    int maxProfit(vector<int>& prices) {
        const int N = 1e5 + 11;
        int f[N][2] = {0};
        f[0][1] -= 2*prices[0];//处理初始状态：第一天不能卖出
        for(int i = 0; i < prices.size(); ++ i)
        {
            //无股票：继承或卖出
            f[i + 1][0] = max(f[i][0], f[i][1] + prices[i]);
            //有股票：继承或买入
            f[i + 1][1] = max(f[i][1], f[i][0] - prices[i]);
        }

        int ret = max(f[prices.size()][0], f[prices.size()][1]);
        return ret;
    }
};