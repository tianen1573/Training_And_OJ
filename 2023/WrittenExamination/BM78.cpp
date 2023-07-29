class Solution {
public:
    
    // f[i][2] : 0：第i家不偷，1：偷
    int rob(vector<int>& nums) {
        
        vector<vector<int>> f(nums.size() + 11, vector<int>(2, 0));
        f[1][0] = 0, f[1][1] = nums[0];

        for(int i = 1; i < nums.size(); ++ i)
        {
            // 不偷i
            f[i + 1][0] = max(f[i][0], f[i][1]);
            // 偷i
            f[i + 1][1] = f[i][0] + nums[i];
        }

        int ret = max(f[nums.size()][0], f[nums.size()][1]);
        return ret;
    }
};