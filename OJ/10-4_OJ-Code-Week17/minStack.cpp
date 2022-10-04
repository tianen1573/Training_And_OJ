
/*155. ��Сջ*/
/* https://leetcode.cn/problems/min-stack/ */


class MinStack {
private:
    stack<int> _sta;
    stack<int> _min;
public:
    MinStack() {
        //�Ÿ����ֵ, �����һ��push�����, ��Ϊû��top
        _min.push(INT_MAX);
    }
    
    void push(int val) {
        _sta.push(val);

        if(val <= _min.top())
        {
            _min.push(val);
        } 
    }
    
    void pop() {
        
        if(_sta.top() == _min.top())
        {
            _sta.pop();
            _min.pop();
        }
        else
        {
            _sta.pop();
        }

    }
    
    int top() {

        return _sta.top(); 
    }
    
    int getMin() {
        
        return _min.top();
    }
};
