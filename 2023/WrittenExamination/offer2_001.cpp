class Solution {
public:
    int divide(int a, int b) {
        
        // 1. 三个特殊情况
        if(a == 0) return 0;
        if(a == INT_MIN) 
        {
            if(b == - 1)
                return INT_MAX;
            if(b == 1)
                return INT_MIN;
        }
        if(b == INT_MIN)
        {
            if(a == INT_MIN) return 1;
            else return 0;
        }
        
        // 2. 转为负数
        bool flag = false;
        if((a > 0 && b > 0) || (a < 0 && b < 0)) flag = true;
        if(a > 0) a = -a;
        if(b > 0) b = -b;

        // 3. 倍增法减少遍历次数
        int res = 0;
        while(a <= b) // 负数
        {
            int cur = b, cnt = -1; // cnt也设置成负数，则a=INT_MIN,b=-1时，可以避免res溢出。前面也特判了这个例子
            while(cur >= a - cur) // 累加求本次 a最多能去掉多少个b
            {
                // cur + cur >= a; 可能会溢出，转换为 cur >= a - cur
                cur += cur;
                cnt += cnt;
            }
            a -= cur;
            res += cnt;
        }
        
        return flag ? -res : res;
    }
};