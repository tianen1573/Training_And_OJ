class Solution {
public:
    bool isStraight(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int val = -1, cnt = 0;
        
        int i = 0;
        for(; i < 5;)
        {
            if(nums[i] == 0) ++ cnt, ++ i;

            else if(val == -1) val = nums[i] + 1, ++ i;
            else
            {
                if(val != nums[i])
                {

                    if(cnt) -- cnt, ++ val;
                    else return false;

                }
                else
                {
                    ++ i;
                    ++ val;
                }
                
            }
        }
        return i == 5;
    }
};