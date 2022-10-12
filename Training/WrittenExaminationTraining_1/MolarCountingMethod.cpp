/*摩尔计数法*/


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return int整型
     */
    int MoreThanHalfNum_Solution(vector<int>& numbers) {
        
        int res = numbers[0];
        int count = 1;
        
        for(auto& val : numbers)
        {
            if(val == res)
            {
                ++count;
            }
            else if(--count == 0)
            {
                res = val;
                count = 1;
            }
        }
        
        return res;
        
    }
};