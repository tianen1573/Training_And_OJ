class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        // 简单的滑动窗口不能满足负数问题。所以往hash方向靠
        // 一开始想的是，统计以i结尾的连续序列的的和为map，然后i+1就可以在这个集合里查找k-[i+1]的序列个数
        // 这样的话每次map需要跟着i更新，应该会超时
        // 官解: 连续序列的和pre[j, i] = pre[i] - pre[j - 1] == k ->> pre[i] - k == pre[j - 1]
        // pre[i] - k == pre[j - 1]：则我们只需要找到在i之前没有多少个pre[j-1]就行了


        unordered_map<int, int> hash;
        hash[0] = 1; // 空前缀和
        long long pre = 0; // 以[i]结尾时的前缀和[0,i]
        int ret = 0;

        for(int i = 0; i < nums.size(); ++ i)
        {
            pre += nums[i]; // pre[i]
            if(hash.find(pre - k) != hash.end())
                ret += hash[pre - k]; // pre[j - 1]
            ++ hash[pre]; // 先使用，后入列
        }

        return ret;
    }
};