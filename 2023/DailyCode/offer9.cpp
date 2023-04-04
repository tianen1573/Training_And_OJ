class CQueue {
public:
    CQueue() {
    }
    
    void appendTail(int value) {

        //转移数据
        if(!flag)
        {
            while(!st2.empty())
            {
                st1.push(st2.top());
                st2.pop();
            }
        }
        flag = true;
        st1.push(value);
    }
    
    int deleteHead() {

        //转移数据
        if(flag)
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        flag = false;

        int ret = -1;

        if(!st2.empty())
        {
            ret = st2.top();
            st2.pop();
        } 

        return ret;
    }
    private:
    stack<int> st1, st2;//st1承担入队，st2承担出队
    bool flag = true;
};