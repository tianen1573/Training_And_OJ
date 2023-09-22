class Solution {
public:
    int fun(int n) 
    {
        int cnt = 0;
        while(n)
        {
            int val = n % 10;
            if(val == 0 || val == 5)
                break;
            
            ++ cnt;
            n /= 10;
        }

        return cnt;
    }
};