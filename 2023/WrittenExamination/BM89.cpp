/**
 * struct Interval {
 *	int start;
 *	int end;
 *	Interval(int s, int e) : start(start), end(e) {}
 * };
 */
class Solution {
public:

    vector<Interval> merge(vector<Interval>& intervals) {
        
        if(intervals.empty()) return vector<Interval>();
        sort(intervals.begin(), intervals.end(), [&](auto &a, auto &b)
        {
            if(a.start != b.start) return a.start < b.start;
            else return a.end < b.end;
        });
        
        vector<Interval> ret;
        int start = intervals[0].start, end = intervals[0].end;
        for(int i = 1; i < intervals.size(); ++ i)
        {
            if(end < intervals[i].start)
            {
                ret.push_back({start, end});
                start = intervals[i].start;
                end = intervals[i].end;
            }
            else 
            {
                end = max(end, intervals[i].end);
            }
        }
        ret.push_back({start, end});

        return ret;
    }
};