class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<int> stk;
        vector<int> ret(temperatures.size());

        for(int i = 0; i < temperatures.size(); ++ i)
        {
            if(stk.empty() || temperatures[i] <= temperatures[stk.top()])
            {
                stk.push(i);
                continue;
            }

            while(stk.size() && temperatures[i] > temperatures[stk.top()])
            {
                int idx = stk.top();
                stk.pop();
                ret[idx] = i - idx;
            }
            stk.push(i);
        }

        while(stk.size())
        {
            int idx = stk.top();
            stk.pop();
            ret[idx] = 0;
        }

        return ret;
    }
};