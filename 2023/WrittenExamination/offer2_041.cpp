class MovingAverage {
private:
    queue<int> que;
    int capa;
    int sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        capa = size;
        sum = 0;
    }
    
    double next(int val) {
        
        que.push(val);
        sum += val;
        
        if(que.size() > capa)
        {
            sum -= que.front();
            que.pop();
        }

        return 1.0 * sum / que.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */