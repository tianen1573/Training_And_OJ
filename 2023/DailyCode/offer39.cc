class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int ans = nums[0];
        int cnt = 1;
        int len = nums.size();

        for(int i = 1; i < len; ++ i)
        {
            if(nums[i] == ans)
                cnt ++;
            else
                -- cnt;
            
            if(0 == cnt)
            {
                ans = nums[i];
                cnt = 1;
            }
        }

        return ans;

    }
};
//栈