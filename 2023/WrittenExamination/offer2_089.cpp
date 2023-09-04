class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.size() == 1)
            return nums[0];

        vector<vector<int>> f(nums.size(), vector<int>(2, 0));
        f[0][1] = nums[0];
        f[1][1] = nums[1];
        f[1][0] = nums[0];

        for(int i = 2; i < nums.size(); ++ i)
        {
            f[i][0] = max(f[i - 1][1], f[i - 1][0]);
            f[i][1] = f[i - 1][0] + nums[i];
        }

        return max(f[nums.size() - 1][1], f[nums.size() - 1][0]);
    }
};