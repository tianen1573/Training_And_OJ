//不用加减乘除做加法
//https://www.nowcoder.com/questionTerminal/59ac416b4b944300b617d4f7f111b215
class Solution {
public:
    int Add(int num1, int num2) 
    {
        int a = num1, b = num2;
            
        int cry = 0, res = 0;
        
        for(int i = 0; i < 32; ++ i)
        {
            int A = (a >> i) & 1;
            int B = (b >> i) & 1;
            
            int Cry = 1;
            if(A)
                Cry <<= 1;
            if(B)
                Cry <<= 1;
            if(cry)
                Cry <<= 1;
            
            if(Cry == 1)
                continue;
            else if(Cry == 2)
            {
                cry = 0;
                res |= (1 << i);
            }
            else if(Cry == 4)
            {
                cry = 1;
            }
            else if(Cry == 8)
            {
                cry = 1;
                res |= (1 << i);
            }
        }
        
        return res;
    }
};