class Solution {
    vector<int> pre;
    vector<int> w;
    int sum = 0;
public:
    Solution(vector<int>& w) {
        this->w = w;
        for(int i = 0; i < w.size(); ++ i)
        {
            sum += w[i];
            pre.push_back(sum);
        }
    }
    
    int pickIndex() {

        // 前缀和为[1, sum]
        int randn = rand() % sum + 1;

        int l = 0, r = pre.size() - 1;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(pre[mid] >= randn)
                r = mid;
            else
                l = mid + 1;
        }

        return l;//返回下标
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */