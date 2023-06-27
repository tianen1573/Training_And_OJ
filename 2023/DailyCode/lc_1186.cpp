class Solution {
public:

    // left存储i的左连续元素区间最大值，rig存储右边的
    // 则遍历到i时， 左区间为空，则left[i]为0；若不为空，其左连续区间必须包含i-1，则转换成了[i-1]+left[i-1]
    // 右区间同理
    // 因为是vector，下标从0开始，需要转换一下
    int maximumSum(vector<int>& arr) {

        const int N = arr.size() + 11;
        int n = arr.size();
        int left[N], rig[N];
        memset(left, 0, sizeof left);
        memset(rig, 0, sizeof rig);

        for(int i = 1; i < n; ++ i)
            left[i + 1] = max(left[i + 1], arr[i - 1] + left[i]);
        for(int i = n - 2; i >= 0; -- i)
            rig[i + 1] = max(rig[i + 1], arr[i + 1] + rig[i + 2]);
        
        int res = INT_MIN;
        for(int i = 0; i < n; ++ i)
        {
            int l = max(0, left[i + 1]);
            int r = max(0, rig[i + 1]);
            int sum = l + r;

            //sum==0时，我们默认为区间元素只有i，
            //可能会影响 以i为切割点的区间的和最大值
            //但不影响整个数组的子数组最大值
            if(sum == 0) sum += arr[i];
            else if(arr[i] > 0) sum += arr[i];
            
            res = max(res, sum);
        }

        return res;
    }
};