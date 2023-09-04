class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.size() == 1)
            return nums[0];

        const int N = nums.size() + 11;
        int f[N][2];
        int ret = 0;

        // 第一家不偷， 则最后一家可偷可不偷
        memset(f, 0, sizeof f);
        f[1][0] = f[1][1] = 0;
        for(int i = 1; i < nums.size(); ++ i)
        {
            f[i + 1][0] = max(f[i][1], f[i][0]);
            f[i + 1][1] = f[i][0] + nums[i];
        }
        ret = max(f[nums.size()][1], f[nums.size()][0]);
        
        //第一家偷，则最后一家只能不偷
        //因为第一家偷了，所以第二家需要强制性不偷
        memset(f, 0, sizeof f);
        f[1][0] = 0, f[1][1] = nums[0];
        f[2][1] = f[2][0] = f[1][1];
        for(int i = 2; i < nums.size(); ++ i)
        {
            f[i + 1][0] = max(f[i][1], f[i][0]);
            f[i + 1][1] = f[i][0] + nums[i];
        }
        ret = max(ret, f[nums.size()][0]);

        return ret;
    }
};