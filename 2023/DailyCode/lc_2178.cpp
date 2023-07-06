class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        
        vector<long long> ret;

        if(finalSum & 1) return ret;

        long long cur = 2;
        while(finalSum >= cur)
        {
            ret.push_back(cur);

            finalSum -= cur;
            cur += 2;
        }
        if(finalSum > 0)
        ret[ret.size() - 1] += finalSum;

        return ret;

    }
};