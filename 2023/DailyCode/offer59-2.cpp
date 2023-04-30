class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {

        if(_que.empty()) return -1;

        return _deq.front();
    }
    
    void push_back(int value) {

        _que.push(value);

        while(!_deq.empty() && _deq.back() < value) 
            _deq.pop_back();
        
        _deq.push_back(value);

    }
    
    int pop_front() {

        if(_que.empty()) return -1;

        int ret = _que.front();
        _que.pop();

        if(ret == _deq.front())
            _deq.pop_front();

        return ret;
    }
private:
    deque<int> _deq;
    queue<int> _que;
};
//单调双端队列
//同滑动窗口最大值

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */