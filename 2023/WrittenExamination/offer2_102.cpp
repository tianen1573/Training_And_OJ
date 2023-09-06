class Solution {
public:

    const int N = 1000;

    int findTargetSumWays(vector<int>& nums, int target) {

        //f[i][j]：走到第i个时，值为j的个数
        int n = nums.size();
        vector<vector<int>> f(n, vector<int>(2011, 0));
        ++ f[0][nums[0] + N], ++ f[0][-nums[0] + N];

        for(int i = 1; i < n; ++ i)
        {
            // -1000 <= val + [i] <= 1000 -->>> -1000 <= val <= 1000 - [i]
            // -1000 <= val - [i] <= 1000 -->>> -1000 + [i] <= val <= 1000
            int left = -1000, rig = -1000 + nums[i];
            for(; left < rig; ++ left)
            {
                f[i][left + nums[i] + N] += f[i - 1][left + N];
            }
            rig = 1000 - nums[i];
            for(; left <= rig; ++ left)
            {
                f[i][left + nums[i] + N] += f[i - 1][left + N];
                f[i][left - nums[i] + N] += f[i - 1][left + N];
            }
            rig = 1000;
            for(; left <= rig; ++ left)
            {
                f[i][left - nums[i] + N] += f[i - 1][left + N];
            }
        }
        // 优化
        // 记数组的元素和为 sum，添加 - 号的元素之和为 neg，则其余添加 + 的元素之和为 sum−neg，
        // 得到的表达式的结果为 (sum−neg)−neg=sum−2⋅neg=target
        // 即 2 * neg = (sum - target)
        // 由于数组 nums 中的元素都是非负整数，neg 也必须是非负整数，
        // 所以上式成立的前提是 sum−target 是非负偶数。若不符合该条件可直接返回 0。
        // 若上式成立，问题转化成在数组 nums 中选取若干元素，使得这些元素之和等于 neg

        return f[n - 1][target + N];
    }
};