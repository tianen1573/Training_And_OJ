

/* 用队列实现栈 */
/* https://leetcode.cn/problems/implement-stack-using-queues/ */


class MyStack {

    queue<int> _fir;
    queue<int> _sec;

    bool sta = true;

public:
    MyStack() {

        sta = true;

    }
    
    void push(int x) {

        _fir.push(x);

    }
    
    int pop() {

        while(_fir.size() > 1)
        {
            _sec.push(_fir.front());
            _fir.pop();
        }

        int _top = _fir.front();
        _fir = _sec;
        _sec = queue<int>();//匿名对象

        return _top;

    }
    
    int top() {

        while(_fir.size() > 1)
        {
            _sec.push(_fir.front());
            _fir.pop();
        }
        int _top = _fir.front();
        _sec.push(_top);
        _fir = _sec;
        _sec = queue<int>();

        return _top;


    }
    
    bool empty() {

        return _fir.empty();

    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */