class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> que; // 默认的是大根堆
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto val : nums)
        {
            que.push(val);
            if(que.size() > k)
                que.pop();
        }
    }
    
    int add(int val) {
        
        que.push(val);
        if(que.size() > k)
            que.pop();

        return que.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */