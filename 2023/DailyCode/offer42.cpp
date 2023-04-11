class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int last = 0;
        int maxVal = INT_MIN;

        for(auto val : nums)
        {
            //是否和前面的子数组连接
            if(last < 0)//前面子数组为负，不连接
            {
                last = val;
            }
            else//为正，连接
            {
                last += val;val;
            }
            //更新最大值
            maxVal = max(maxVal, last);
        }

        return maxVal;

    }
};