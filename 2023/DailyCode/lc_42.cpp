class Solution {
public:

    // by灵茶山艾府
    int trap(vector<int>& height) {
        
        // int n = height.size();
        // vector<int> preArr(n);
        // vector<int> sufArr(n);
        // preArr[0] = height[0];
        // sufArr[n - 1] = height[n - 1];

        // for(int i = 1; i < n; ++ i)
        //     preArr[i] = max(preArr[i - 1], height[i]);
        // for(int i = n - 2; i >= 0; -- i)
        //     sufArr[i] = max(sufArr[i + 1], height[i]);
        
        // int ans = 0;
        // for(int i = 0; i < n; ++ i)
        // {
        //     int hgh = min(sufArr[i], preArr[i]);
        //     ans += hgh - height[i];
        // }

        // return ans;

        int left = 0, rig = height.size() - 1;
        int pre = 0, suf = 0;
        int ans = 0;
        while(left < rig)
        {
            pre = max(pre, height[left]);
            suf = max(suf, height[rig]);

            if(pre > suf)
            {
                ans += suf - height[rig];
                -- rig;
            }
            else
            {
                ans += pre - height[left];
                ++ left;
            }
        }

        return ans;
    }
};