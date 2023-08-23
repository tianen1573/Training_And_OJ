class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        typedef pair<int, int> PII;
        unordered_map<int, int> cntHash;
        priority_queue<PII, vector<PII>, greater<PII>> que;

        // 统计次数
        for(auto val : nums)
            ++ cntHash[val];
        // 入堆
        vector<int> ans;
        for(auto [x, y] : cntHash)
        {
            que.push({y, x});
            if(que.size() > k)
                que.pop();
        }
        // 入数组
        while(que.size())
        {
            ans.push_back(que.top().second);
            que.pop();
        }
        return ans;
    }
};