class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // 我们把两个数看成一个整体
        // 在插入之前，相同的两个数的下标是 偶数奇数
        // 在插入之后，插入下标为x，x前还是偶数奇数，x后变成了奇数偶数
        // 则我们判断mid的下标奇偶性
        // 如果满足偶数奇数排序，代表x在mid的后面
        // 否则x在mid的前面，因为此时已经打乱了偶奇排列
        int l = 0, r = nums.size() - 1;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(nums[mid] == nums[mid ^ 1]) // 满足偶奇
                l = mid + 1;
            else // 不满足
                r = mid;
        }

        return nums[l];
    }
};