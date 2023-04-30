class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans;
        
        int len = nums.size();

        //数组为空，或者数组大小不够窗口
        if(!len || len < k) return ans;

        deque<int> deq;

        for(int i = 0; i < len; ++ i)
        {
            //假定队列的元素，和当前元素在同一个窗口
            //队列的最后一个元素小于当前元素，则队列的最后一个元素肯定不是当前元素存在时的窗口最大值
            //因为当前元素在的窗口，其最大值是大于等于当前元素的，一定大于队尾元素
            while(!deq.empty() && nums[deq.back()] < nums[i]) deq.pop_back();

            //把当前值入队
            deq.push_back(i);

            //队列元素可能过期
            if(deq.front() < i - k + 1)
            {
                deq.pop_front();
            }

            //够k个元素，才形成窗口
            if(i >= k - 1)
            {
                ans.push_back(nums[deq.front()]);
            }
        }


        return ans;
    }
};