class Solution {
public:
    // n * n -->> k * k : k <= n
    // 每个数组最多使用前k个，就能求出答案
    // n * n -->> klogk
    // 先让数组1的第一个元素，匹配数字2的全部元素，此时最小的一定在堆里
    // 每次出去一个元素(x,y)，仅移动y就行
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        // lambda
        auto cmp = [&nums1, &nums2](const pair<int, int> &a, const pair<int, int> &b)
        {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };

        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(cmp);

        // 放入k个元素
        for(int i = 0; i < min(k, m); ++ i)
        {
            que.emplace(i, 0);
        } 
        
        // x一定时，y上升，和上升
        // 哪一个(x, y)出堆了，就把他的后继(x, y + 1)入堆
        while(k -- > 0 && que.size())
        {
            auto [x, y] = que.top();
            que.pop();

            ans.push_back({nums1[x], nums2[y]});

            if(y + 1 < n)
                que.emplace(x, y + 1);
        }

        return ans;
    }
};