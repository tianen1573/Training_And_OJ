#include <functional>
class Solution {
public:

    int minmumNumberOfHost(int n, vector<vector<int> >& startEnd) {
        
        sort(startEnd.begin(), startEnd.end(), [&](auto &a, auto &b)
        {
            if(a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1];
        });
        priority_queue<int, vector<int>, greater<int>> que;

        int ans = 0;
        for(int i = 0; i < startEnd.size(); ++ i)
        {
            while(que.size() && que.top() <= startEnd[i][0]) que.pop();
            que.push(startEnd[i][1]);
            ans = max(ans, (int)que.size());
        }
        
        return ans;
    }
};