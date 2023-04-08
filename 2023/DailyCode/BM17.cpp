class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @param target int整型 
     * @return int整型
     */
    int search(vector<int>& nums, int target) {
        
        int l = 0, r = nums.size() - 1;
        int pos = -1;
        while(l <= r)
        {
            int mid = l + ((r - l) >> 1);
            if(target == nums[mid])
            {
                pos = mid;
                break;
            }
            else if(target > nums[mid])
                l = mid + 1;
            else
                r = mid - 1;
        }

        return pos;
    }
};