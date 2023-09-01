class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int l = 0, r = nums.size() - 1;

        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(nums[mid] >= target)
                r = mid;
            else 
                l = mid + 1;
        }

        // nums[l] >= target,否则插入到最后一个位置
        return nums[l] >= target ? l : l + 1;
    }
};