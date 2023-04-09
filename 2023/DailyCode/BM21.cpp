class Solution {
public:
    int minNumberInRotateArray(vector<int> arr) {

        int left = 0, right = arr.size() - 1;
        
        while(left < right)
        {
            int mid = (left + right) >> 1;

            if(arr[mid] < arr[right]) right = mid;
            else if(arr[mid] > arr[right]) left = mid + 1; 
            else -- right;
        }

        return arr[left];
        
    }
};
