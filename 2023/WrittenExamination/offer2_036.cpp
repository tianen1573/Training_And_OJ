class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        unordered_set<string> hash = {"+", "-", "*", "/"};
        stack<int> stk;
        int ans = 0;

        for(auto &str : tokens)
        {
            if(hash.count(str) != 0)
            {
                int rig = stk.top();
                stk.pop();
                int left = stk.top();
                stk.pop();
                
                if(str == "+")
                    stk.push(left + rig);
                else if(str == "-")
                    stk.push(left - rig);
                else if(str == "*")
                    stk.push(left * rig);
                else if(str == "/")
                    stk.push(left / rig);
            }
            else
            {
                int num = stoi(str);
                stk.push(num);
            }
        }

        return stk.top();
    }
};