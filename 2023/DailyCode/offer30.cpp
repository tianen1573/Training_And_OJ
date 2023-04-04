//使用辅助栈，保存第n个元素入栈后的最小元素
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        _minStk.push(INT_MAX);
    }
    
    void push(int x) {
        
        _stk.push(x);
        _minStk.push(std::min(x, _minStk.top()));
    }
    
    void pop() {

        _minStk.pop();
        _stk.pop();

    }
    
    int top() {

        return _stk.top();

    }
    
    int min() {

        return _minStk.top();
    }

private:
    stack<int> _stk;
    stack<int> _minStk;
};