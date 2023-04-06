class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int l = 0, r = nums.size() - 1;

        while(l < r)
        {
            int mid = l + ((r - l) >> 1);
            if(nums[mid] == mid)
                l = mid + 1;
            else
                r = mid;
        }
        return nums[l] == l ? l + 1 : l;
    }
};