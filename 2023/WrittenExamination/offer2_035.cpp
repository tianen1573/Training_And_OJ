class Solution {
public:
    int toMinute(string & str)
    {
        int ret = 0;
        ret += (((str[0] - '0') * 10 + (str[1] - '0')) * 60);
        ret += ((str[3] - '0') * 10 + str[4] - '0');

        return ret;
    }
    int findMinDifference(vector<string>& timePoints) {
        
        //鸽巢原理
        //根据题意，一共有24×60=1440种不同的时间。由鸽巢原理可知，如果timePoints的长度超1440，  
        //那么必然会有两个相同的时间，此时可以直接返回 0。
        if(timePoints.size() >= 1440) return 0;

        vector<int> arr;
        for(auto &str : timePoints)
        {
            arr.push_back(toMinute(str));
        }
        sort(arr.begin(), arr.end());
        // sub = 大 - 小 或者 INT_Minute - (大 - 小)
        int len = arr.size();
        int minSub = 24 * 60 - (arr[len - 1] - arr[0]);
        for(int i = 1; i < len; ++ i)
        {
            minSub = min(minSub, arr[i] - arr[i - 1]);
        }

        return minSub;
    }
};