class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {

        int res = 0;

        if(numOnes >= k)
        {
            res = k;
        }
        else
        {
            res = numOnes;
            k -= numOnes;
            if(numZeros < k)
            {
                k -= numZeros;
                res -= k;
            }
        }

        return res;
        
    }
};