class Solution {
public:
    vector<int> exchange(vector<int>& nums) {

        int fast = 0, eve = 0;

        for(; fast < nums.size(); ++ fast)
        {
            if(nums[fast] % 2)
            {
                while(eve < nums.size() && nums[eve] % 2)
                    ++ eve;
                if(eve < fast)
                    swap(nums[eve], nums[fast]);
            }
        }

        return nums;

    }
};