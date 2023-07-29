class Solution {
public:

    int maxProfit(vector<int>& prices) {
        
        int minPri = 0x3f3f3f3f;
        int ret = 0;
        for(int i = 0; i < prices.size(); ++ i)
        {
            minPri = min(minPri, prices[i]);
            ret = max(ret, prices[i] - minPri);
        }

        return ret;
    }
};