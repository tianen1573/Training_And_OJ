class Solution {
public:
    bool canPartition(vector<int>& nums) {

        const int n = nums.size();
        if(n < 2) 
            return false;
        int sum = 0, maxVal = 0;
        for(auto val : nums)
        {
            sum += val;
            maxVal = max(maxVal, val);
        }
        if(sum & 1 || maxVal > sum / 2)
            return false;

        int tar = sum / 2;
        
        // f[i][j]：选到第i个时， 能否构成 j
        vector<vector<bool>> f(n, vector<bool>(tar + 1, false));
        f[0][0] = f[0][nums[0]] = true;
        for(int i = 1; i < n; ++ i)
        {
            for(int j = 0; j <= tar; ++ j)
            {
                // 第i个一定不选
                if(j < nums[i])
                    f[i][j] = f[i - 1][j];
                else // 不选或选
                    f[i][j] = f[i - 1][j] | f[i - 1][j - nums[i]];
            }
        }

        return f[n - 1][tar];
    }
};