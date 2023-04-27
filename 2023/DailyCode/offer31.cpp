class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> pushStk;
        int i = 0, j = 0;

        for(; i < pushed.size(); ++ i)
        {
            if(pushed[i] == popped[j])
            {
                ++ j;
                while(!pushStk.empty())
                {
                    if(pushStk.top() == popped[j])
                    {
                        ++ j;
                        pushStk.pop();
                    }
                    else
                        break;
                }
            }
            else
            {
                pushStk.push(pushed[i]);
            }
        }

        while(!pushStk.empty())
        {
            if(pushStk.top() == popped[j])
            {
                ++ j;
                pushStk.pop();
            }
            else
                break;
        }

        return pushStk.empty();
    }
};