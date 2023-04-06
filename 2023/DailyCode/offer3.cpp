class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {

        for(int i = 0; i < nums.size(); )
        {
            if(nums[i] != i)
            {
                int k = nums[nums[i]];
                if(k == nums[i]) return k;
                else
                {
                    nums[nums[i]] = nums[i];
                    nums[i] = k;
                }
            }
            else
                ++ i;
        }

        return -1;
    }
};