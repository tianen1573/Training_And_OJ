class Solution {
public:

    // f[i][2] : 0：第i家不偷，1：偷
    // 分情况讨论：第一家店偷不偷
    int rob(vector<int>& nums) {
        
        const int N = 2e5 + 11;
        int f[N][2];

        //第一家店不偷
        memset(f, 0, sizeof f);
        f[1][0] = 0, f[1][1] = 0;
        for(int i = 1; i < nums.size(); ++ i)
        {
            // 不偷i
            f[i + 1][0] = max(f[i][0], f[i][1]);
            // 偷i
            f[i + 1][1] = f[i][0] + nums[i];
        }
        int ret = max(f[nums.size()][0], f[nums.size()][1]); // 则最后一家店偷不偷都行
        //第一家店偷
        memset(f, 0, sizeof f);
        f[1][0] = 0, f[1][1] = nums[0]; // 1
        f[2][0] = f[2][1] = f[1][1]; // 1
        for(int i = 2; i < nums.size(); ++ i)
        {
            // 不偷i
            f[i + 1][0] = max(f[i][0], f[i][1]);
            // 偷i
            f[i + 1][1] = f[i][0] + nums[i];
        }
        ret = max(ret, f[nums.size()][0]); // 则最后一家店只能不偷

        return ret;
    }
};