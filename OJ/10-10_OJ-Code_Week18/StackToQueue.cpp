

/*用站实现队列*/
/* https://leetcode.cn/problems/implement-queue-using-stacks/ */

class MyQueue {

private:
    stack<int> _fir;
    stack<int> _sec;


public:
    MyQueue() {

        ;
    }
    
    void push(int x) {

        _fir.push(x);

    }
    
    int pop() {

        if(_sec.empty())
        {

            while(!_fir.empty())
            {
                int _top = _fir.top();
                _sec.push(_top);
                _fir.pop();
            }
        }

        int _top = _sec.top();
        _sec.pop();

        return _top;

    }
    
    int peek() {

        if(_sec.empty())
        {
            while(!_fir.empty())
            {
                int _top = _fir.top();
                _sec.push(_top);
                _fir.pop();
            }
        }

        int _top = _sec.top();

        return _top;

    }
    
    bool empty() {

        return _fir.empty() && _sec.empty();

    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */