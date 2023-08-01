#include <unordered_map>
class Solution {
public:

    int maxLength(vector<int>& arr) {
        
        unordered_map<int, int> hash;
        queue<int> que;

        int retMax = 0;
        for(auto val : arr)
        {
            que.push(val);
            ++ hash[val];

            while(hash.size() && hash[val] > 1)
            {
                -- hash[que.front()];
                que.pop();
            }

            if(que.size() > retMax)
                retMax = que.size();
        }

        return retMax;
    }
};