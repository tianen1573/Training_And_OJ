class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int left = 0, rig = nums.size() - 1;

        while(left < rig)
        {
            if(nums[left] + nums[rig] == target)
            {
                vector<int> ans = {nums[left], nums[rig]};
                return ans;
            }
            else if(nums[left] + nums[rig] > target)
                -- rig;
            else
                ++ left;
        }

        return vector<int>();

    }
};