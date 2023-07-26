class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
       
        int len = cost.size();

       for(int i = 2; i < len; ++ i)
            cost[i] += min(cost[i - 1], cost[i - 2]);
        
        int ret = 0;
        if(len == 1) ret = cost[0];
        else ret = min(cost[len - 1], cost[len - 2]);

        return ret;
    }
};