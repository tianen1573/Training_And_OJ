class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 滑动窗口
        long long sum = 0;
        int cnt = 0, res = 1e5+11;
        int l = 0, r = 0;
        while(r < nums.size())
        {
            sum += nums[r ++];
            ++ cnt;
            while(cnt && sum >= target)
            {
                res = min(res, cnt);
                sum -= nums[l ++];
                cnt --;
            }
        }     

        return res == 1e5+11 ? 0 : res;   
    }
};