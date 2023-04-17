class Solution {
public:
    string reverseWords(string s) {
        string tmp;
        stack<string> stk;
        
        for(int i = 0; i < s.size(); )
        {
            if(s[i] != ' ')
            {
                int end = s.find(' ', i);
                if(end == -1) end = s.size();
                tmp = s.substr(i, end - i);
                stk.push(tmp);

                i = end;
            }
            else ++ i;
        }

        string ans;
        while(!stk.empty())
        {
            ans += stk.top();
            stk.pop();

            if(!stk.empty())
                ans += ' ';
        }


        return ans;

    }
};