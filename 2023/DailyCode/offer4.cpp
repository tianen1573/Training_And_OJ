class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {

        if(matrix.size() == 0) return false;

        int r = 0, c = matrix[0].size() - 1;

        while(r < matrix.size() && c >= 0)
        {
            if(matrix[r][c] == target) return true;
            else if(matrix[r][c] > target) -- c;
            else ++ r;
        }

        return false;

    }
};