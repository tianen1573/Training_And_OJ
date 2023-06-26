class Solution {
public:
    vector<int> maxInWindows(const vector<int>& nums, unsigned int size) {
        
        vector<int> ans;
        int len = nums.size();
        int k = size;
        if(!len || len < k || k < 1) return ans;//数组为空， 数组不够窗口大小， 窗口大小为空

        deque<int> deq;

        for(int i = 0; i < len; ++ i)
        {
            //如果队尾最后一个元素比窗口的最后一个小，则队尾的元素一定不可能是窗口的最大值
            while(!deq.empty() && nums[deq.back()] < nums[i])
            {
                deq.pop_back();
            }

            //可以保证，队列不为空，且至少有一个合法元素。
            deq.push_back(i);

            if(deq.front() < i - k + 1)//队头不在窗口里
            {
                deq.pop_front();
            }
            if(i >= k - 1)//至少要满足窗口大小，才存在窗口内最大值
            {
                ans.push_back(nums[deq.front()]);
            }
        }

        return ans;
    }
};