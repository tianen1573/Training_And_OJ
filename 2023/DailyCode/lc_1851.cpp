#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:

    //根据左右区间端点进行二分暴力，TIM
    //可以发现的是，que数组升序排序后，还按照当前解法做的话，有很多地方是重复的
    //比如，左端点的范围，和que数组一样，是升序变大的，可以使用单调队列
    //题解优化决定不看
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        map<int, vector<int>*> mkv;
        for(auto &vec : intervals)
        {
            int l = vec[0], r = vec[1];
            if(mkv.find(l) == mkv.end())
            {
                vector<int> *arr = new vector<int>();
                mkv[l] = arr;
            }

            vector<int> *ptr = mkv[l];
            (*ptr).push_back(r);
        }
        for(auto &it : mkv)
        {
            auto &arr = *(it.second);
            sort(arr.begin(), arr.end());
        }

        vector<int> res;
        for(auto val : queries)
        {
            int minLen = 1e7+11;
            map<int, vector<int>*>::iterator it = mkv.begin();
            while(it->first <= val && it != mkv.end())
            {
                auto &arr = *(it->second);
                auto ret = lower_bound(arr.begin(), arr.end(), val);
                if(ret != arr.end())
                    minLen = min(minLen, *ret - it->first + 1);
                ++ it;
            }
            if(minLen == 1e7+11) minLen = -1;

            res.push_back(minLen);
        }

        return res;
    }
};