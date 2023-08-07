class Solution {
public:

    vector<int> spiralOrder(vector<vector<int> >& matrix) {

        vector<int> ans;
        if(matrix.size() == 0) return ans;

        int up = 0, down = matrix.size() - 1;
        int left = 0, rig = matrix[0].size() - 1;

        while(up < (matrix.size() + 1) / 2 && left < (matrix[0].size() + 1) / 2)
        {
            // 左到右
            for(int i = left; i <= rig; ++ i)
                ans.push_back(matrix[up][i]);
            // 上到下
            for(int i = up + 1; i <= down; ++ i)
                ans.push_back(matrix[i][rig]);
            //右到左
            for(int i = rig - 1; up != down && i >= left; -- i)
                ans.push_back(matrix[down][i]);
            //下到上
            for(int i = down - 1; left != rig && i >= up + 1; -- i)
                ans.push_back(matrix[i][left]);

            ++ up, ++ left;
            -- down, -- rig;
        }

        return ans;

    }
};