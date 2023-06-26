
class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return bool布尔型
     */
    bool isValid(string s) {
        // write code here

        for(auto ch : s)
        {
            if(ch == '}' && _stk.size() && _stk.top() == '{' )
                _stk.pop();
            else if(ch == ']' && _stk.size() && _stk.top() == '[')
                _stk.pop();
            else if(ch == ')' && _stk.size() && _stk.top() == '(')
                _stk.pop();
            else
                _stk.push(ch);
        }

        return _stk.empty();

    }

    stack<char> _stk;
};