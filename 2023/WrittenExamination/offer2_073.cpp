class Solution {
public:

    int minCnt(vector<int>& piles, int k)
    {
        int cnt = 0;
        for(int i = 0; i < piles.size(); ++ i)
        {
            cnt += piles[i] / k;
            cnt += !!(piles[i] % k);
        }

        return cnt;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        long long minK = INT_MAX, maxK = INT_MIN;
        for(int i = 0; i < piles.size(); ++ i)
        {
            maxK = max(maxK, (long long)piles[i]);
        }
        minK = 1;

        while(minK < maxK)
        {
            long long tmp = (minK + maxK) >> 1;
            int cnt = minCnt(piles, tmp);

            if(cnt <= h)
                maxK = tmp;
            else
                minK = tmp + 1;
        }

        return minK;
    }
};