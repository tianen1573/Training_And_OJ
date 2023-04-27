class Solution {
public:
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> arr;

        if(matrix.size() == 0) return arr;

        //记录边界
        int l = 0, r = matrix[0].size() - 1;
        int u = 0, d = matrix.size() - 1;

        //方向数组
        int Dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
        int D = 0;

        //当前位置
        int col = 0, row = 0;
        

        while(col >= l && col <= r && row >= u && row <= d)//合法位置
        {
            arr.push_back(matrix[row][col]);
            
            //若下一个坐标不合法，更改方向
            //更改方向后的下一个位置如果还不合法，就代表已经遍历完了。
            if(row + Dir[D][0] < u || row + Dir[D][0] > d || col + Dir[D][1] < l || col + Dir[D][1] > r)
            {
                if(D == 0) ++ u;
                else if(D == 1) -- r;
                else if(D == 2) -- d;
                else if(D == 3) ++ l;

                D = (D + 1) % 4;

            }
                

            row += Dir[D][0];
            col += Dir[D][1]; 

            cout << Dir[D][0] << ' ' << Dir[D][1] << ' ' << row << " " << col << endl;
        }

        return arr;

    }
};