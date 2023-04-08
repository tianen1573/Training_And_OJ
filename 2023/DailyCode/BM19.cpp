class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型
     */
    int findPeakElement(vector<int>& nums) {
        // write code here

        int l = 0, r = nums.size() - 1;

        while(l < r)
        {
            int mid = l + (r - l) / 2;

            if(nums[mid] <= nums[r]) l = mid + 1;//右边一定有峰
            else r = mid;//小于， 不一定有
        }

        return l;
    }
};