#include <bitset>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型
     */
    int minNumberDisappeared(vector<int>& nums) {
        // write code here

        bitset<500011> bs;
        for(auto t : nums)
            if(t > 0) bs.set(t);
        for(int i = 1; i <= nums.size(); ++ i)
            if(bs.test(i) == false) return i;
        
        return nums.size() + 1;
    }
};