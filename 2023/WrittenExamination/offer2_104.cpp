class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // f[i][j]：
        // 通常情况下，是指走到第i个时，和为j 的组合数
        // 但这道题要求顺序，上述表示没法判断顺序
        // 所以这道题表示为，和为i的组合，最后一个元素时j时的组合数，
        // 此时f[i][j] = f[i - nums[j]][0~n]，不关心倒数第二个元素是啥
        // 因此， 可以转换为f[i]，通过for循环控制组合元素的结尾

        vector<int> f(target + 1);
        f[0] = 1; // 构成0则只有一个不选的方案

        for(int i = 1; i <= target; ++ i)
        {
            for(auto & val : nums)
            {
                // i >= val，才能以val结尾
                // f[i - val] + f[i] < INT_MAX -->> f[i - val] < INT_MAX - f[i] 防溢出
                if(i >= val && f[i - val] < INT_MAX - f[i])
                    f[i] += f[i - val];
            }
        }

        return f[target];
    }
};