class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minVal = INT_MAX;
        int res = 0;

        for(auto &val : prices)
        {
            if(val < minVal)
            {
                minVal = val;
            }
            else
            {
                res = max(res, val - minVal);
            }
        }
        return res;
    }
};