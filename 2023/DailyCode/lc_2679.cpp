class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        
        for(auto &vec : nums)
            sort(vec.begin(), vec.end(), [&](auto &a, auto &b)
            {
                return a > b;
            });
        
        int gra = 0;

        for(int i = 0; i < nums[0].size(); ++ i)
        {
            int maxVal = 0;
            for(auto & vec : nums)
                maxVal = max(maxVal, vec[i]);
            
            gra += maxVal;
        }

        return gra;
        
    }
};