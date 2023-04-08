class Solution {
public:
    bool Find(int target, vector<vector<int> > arr) {

        if(arr.empty()) return false;

        int row = 0, col = arr[0].size() - 1;
        
        while(row < arr.size() && col >= 0)
        {
            if(arr[row][col] == target) return true;
            else if(arr[row][col] > target) -- col;
            else ++ row;
        }

        return false;
    }
};



