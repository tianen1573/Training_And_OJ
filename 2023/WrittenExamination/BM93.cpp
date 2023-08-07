class Solution {
public:
    // 对撞指针
    // left 和 rig 代表区域的长度，每次移动代表长度-1
    // 每次计算代表长度一定时的局部最优
    // 我们让小的那个指针移动，则长度-1的情况下，高度有可能会变高，即移动后的高度可能比原先的高度高
    // 而若让大的那个指针移动，则高度一定不会大于小的那个，面积一定会缩小
    int maxArea(vector<int>& height) {
        
        int left = 0, rig = height.size() - 1;

        int ret = 0;
        while(left < rig)
        {
            int area = (rig - left) * (height[left] > height[rig] ? height[rig] : height[left]);
            ret = max(ret, area);

            if(height[left] > height[rig])
                -- rig;
            else
                ++ left;
        }
        return ret;
    }
};