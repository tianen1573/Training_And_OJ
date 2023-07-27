class Solution {
public:
    
    // f[i]：以[i]结尾的连续子数组的最大和
    int FindGreatestSumOfSubArray(vector<int>& array) {
        
        int ret = array[0];
        for(int i = 1; i < array.size(); ++ i)
        {
            array[i] += array[i - 1] > 0 ? array[i - 1] : 0;
            ret = max(ret, array[i]);
        }

        return ret;
    }
};