// class Solution {
// public:
//     int minArray(vector<int> &nums) {
//         int left = -1, right = nums.size() - 1; // 开区间 (-1, n-1]
//         while (left + 1< right) { // 开区间不为空
//             int mid = left + (right - left) / 2;
//             if (nums[mid] < nums[right]) right = mid; // 中间的比右边的小，此时mid一定在右边低线段
//             else if (nums[mid] > nums[right]) left = mid + 1; //中间的比右边的大 此时mid高线段
//             else --right;//平的，左移
//         }
//         return nums[right];
//     }
// };

class Solution {
public:
    int minArray(vector<int>& numbers) {
        // int _min = 9999;

        // for(auto& v : numbers)
        // {
        //     if(v < _min)
        //     {
        //         _min = v;
        //     }
        // }
        // return _min;

        int l = 0, r = numbers.size() - 1;
        while (l < r) 
        {
            int mid = ((r - l) >> 1) + l;
            //只要右边比中间大，那右边一定是有序数组
            if (numbers[r] > numbers[mid]) {
                r = mid;
            } else if (numbers[r] < numbers[mid]) {
                l = mid + 1;
             //去重
            } else r--;
        }
        return numbers[l];
    }
};