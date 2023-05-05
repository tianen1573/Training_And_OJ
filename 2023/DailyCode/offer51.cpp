class Solution {
public:

    void merge(vector<int>& nums, int left, int rig)
    {
        if(left >= rig) return;

        //先分
        int mid = (left + rig) >> 1;
        merge(nums, left, mid);
        merge(nums, mid + 1, rig);

        //再治
        vector<int> tmp(rig - left + 1);
        int l = left, r = mid + 1;
        int k = 0;
        while(l <= mid && r <= rig)
        {
            //此时左右两部分都是排好序的
            //[l] > [r] -->> [l, mid] > [r]
            if(nums[l] > nums[r])
            {
                ret += (mid - l + 1);
                tmp[k++] = nums[r++];
            }
            else
            {
                tmp[k++] = nums[l++];
            }
        }
        while(l <= mid)
            tmp[k++] = nums[l++];
        while(r <= rig)
            tmp[k++] = nums[r++];
        
        for(k = 0; left <= rig; ++ left, ++ k)
            nums[left] = tmp[k];
    }

    int reversePairs(vector<int>& nums) {

        merge(nums, 0, nums.size() - 1);

        return ret;
    }   
private:
    int ret;
};