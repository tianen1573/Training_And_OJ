class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        // a + b + c = tar 我们固定a的值为[i]，求 b+c+[i] - tar 最小差值 

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 100000;
        for(int i = 0; i <= n - 3; ++ i)
        {
            int l = i + 1, r = n - 1;
            while(l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if(abs(res - target) >= abs(sum - target)) res = sum;
                if(sum > target) -- r;
                else if(sum < target) ++ l;
                else
                {
                    res = target;
                    goto END;
                }
            }
        }

END:
        return res;
    }
};