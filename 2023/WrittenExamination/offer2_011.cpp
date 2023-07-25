class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // 变种前缀和思路
        // 统计遍历到i时，1和0的个数，并求个数差diff
        // 如果在i之前，以及存在差为diff的连续序列j，则i-j[j+1,i]就是连续序列的长度
        // 不存在，就把diff添加到map中，并且易得diff第一次出现时的位置是最优解
        unordered_map<int, int> hash;
        hash[0] = -1;
        int one = 0, zero = 0;
        int ret = 0;

        for(int i = 0; i < nums.size(); ++ i)
        {
            if(nums[i] == 1) ++ one;
            else ++ zero;
            int diff = one - zero;

            if(hash.find(diff) == hash.end())
                hash[diff] = i;

            int j = hash[diff];
            ret = max(ret, i - j);
        }

        return ret;
    }
};