class Solution {
public:
    Solution()
    {
        _min.push(INT_MAX);
    }
    void push(int value) {
        
        _stk.push(value);

        if(value <= _min.top())
            _min.push(value);
    }
    void pop() {

        if(_stk.top() == _min.top())
            _min.pop();
        
        _stk.pop();
        
    }
    int top() {
        
        return _stk.top();
    }
    int min() {
        
        return _min.top();
    }

    stack<int> _min, _stk;
};