class Solution {
public:
    // 排序后，枚举第一个元素，模拟两个元素和为0的情况
    // 三元组不重复，只要前两个不重复，则三元组不重复
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ret;
        int l, r, sum;
        sort(nums.begin(), nums.end()); // 1. 排序

        // 2. 枚举第一个元素
        for(int i = 0; i < nums.size(); ++ i)
        {
            // 当前元素a如果和前一个元素b相等，若{a,c,d}是个合法三元组，则{b,c,d}也是个合法三元组
            // 重复三元组，我们直接跳过这个元素
            if(i > 0 && nums[i - 1] == nums[i]) continue;
            l = i + 1, r = nums.size() - 1;
            while(l < r)
            {
                // 第二个元素同理
                while(l > i + 1 && l < nums.size() && nums[l - 1] == nums[l]) ++ l;
                if(l >= r) break;

                sum = nums[i] + nums[l] + nums[r];
                if(sum == 0)
                {
                    ret.push_back({nums[i], nums[l], nums[r]});
                    ++ l;
                }
                else if(sum > 0)
                {
                    -- r;
                }
                else
                {
                    ++ l;
                }
            }
        }

        return ret;
    }
};