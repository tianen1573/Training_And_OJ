class Solution {
public:
    int mySqrt(int x) {

        if(x == 0 || x == 1)
            return x;
        
        int l = 1, r = x / 2;
        while(l < r)
        {
            int mid = (l + r + 1) >> 1;
            if(mid > x / mid)
                r = mid - 1;
            else
                l = mid;
        }

        return l;

    }
};