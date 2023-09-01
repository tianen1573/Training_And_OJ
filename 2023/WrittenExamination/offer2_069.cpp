class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int l = 0, r = arr.size() - 1;
        // mid 落在左坡，右坡，峰顶
        // l/r = mid 可以避免越界
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
                return mid;
            else if(arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
                l = mid;
            else
                r = mid;
        }

        return -1;
    }
};