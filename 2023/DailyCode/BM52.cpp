class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int>& nums) {
        // write code here

        int x = 0;
        for(auto t : nums) x ^= t;
        for(int i = 0; i < 32; ++ i)
            if(x >> i & 1)
            {
                x = i;
                break;
            }
        int y = 0, z = 0;
        for(auto t : nums)
            if(t >> x & 1) y ^= t;
            else z ^= t;
        
        if(y > z) swap(y,z);
        return vector<int>() = {y,z};

    }
};