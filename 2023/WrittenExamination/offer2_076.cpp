class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // priority_queue<int, vector<int>, greater<int>> prique;
        // for(auto val : nums)
        // {
        //     prique.push(val);
        //     if(prique.size() > k)
        //         prique.pop();
        // }

        // return prique.top();
        
        vector<int> arr;
        for(auto val : nums)
        {
            arr.push_back(val);
            int pos = arr.size() - 1;
            while(pos > 0 && arr[pos] > arr[pos - 1])
            {
                swap(arr[pos], arr[pos - 1]);
                -- pos;
            }
            if(arr.size() > k)
                arr.pop_back();
        }

        return arr[k - 1];
    }
};