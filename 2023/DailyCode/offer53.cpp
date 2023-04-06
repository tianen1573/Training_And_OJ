// class Solution {
// public:
//     int search(vector<int>& nums, int target) {

//         // int cnt = 0;

//         // for(auto num : nums)
//         //     if(num == target)
//         //         ++ cnt;
//         // return cnt;
        
//         // //二分
//         // if(nums.size() == 0) return 0;

//         // int start = 0, end = nums.size() - 1;

//         // int left = 0, right = nums.size() - 1;
//         // while(left < right)
//         // {
//         //     int mid = (left + right) >> 1;
//         //     if(nums[mid] >= target)
//         //         right = mid;
//         //     else
//         //         left = mid + 1;
//         // }
//         // //若不存在，begin和end都指向小于tar的最后一个元素
//         // //若没有提前返回，下面的遍历会死循环
//         // if(nums[right] != target) return 0;
//         // start = right;
//         // left = 0, right = nums.size() - 1;
//         // while(left < right)
//         // {
//         //     int mid = (left + right) >> 1;
//         //     if(nums[mid] <= target)
//         //         left = mid;
//         //     else
//         //     right = mid - 1 ;
//         // }
//         // end = right;

//         // int ret = end - start ? end - start + 1: 0;
//         // return ret;

//     }
// };

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = 0;
        int index = getFirstTargeIndex(nums, target);
        if (index == -1) return res;
        for (int i = index; i < nums.size() && nums[i] == target; i++) {
            res++;
        }
        return res;
    }
private:
    int getFirstTargeIndex(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int res = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid -1;
            } else {
                res = mid;
                right = mid - 1;
            }
        }
        return res;
    }
};
