class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int a = 0, b = 0, c = 0;
        for(int i = 2; i < cost.size(); ++ i)
        {
            c = min(a + cost[i - 2], b + cost[i - 1]);
            a = b;
            b = c;
        }
        int len = cost.size();
        c = min(a + cost[len - 2], b + cost[len - 1]);
        return c;
    }
};