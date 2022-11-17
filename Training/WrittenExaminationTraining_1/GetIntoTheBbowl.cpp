// 快到碗里来
// https://www.nowcoder.com/questionTerminal/82424d93369649b98720743c25edc6ce

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param number int整型 
     * @return int整型
     */
    int jumpFloorII(int number) {
           
        int res = (int)pow(2, number - 1);
        
        return res;
      
    }
};