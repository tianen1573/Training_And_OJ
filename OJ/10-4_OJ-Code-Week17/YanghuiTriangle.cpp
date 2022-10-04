
/*118. Ñî»ÔÈý½Ç*/
/* https://leetcode.cn/problems/pascals-triangle/submissions/ */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        res.push_back(vector<int>(1,1));
        
        for(int i = 2; i <= numRows; ++i)
        {
            vector<int> vec(i);
            vec[0] = vec[i - 1] = 1;
            for(int j = 1; j < i - 1; ++ j)
            {
                vec[j] = res[i - 1 - 1][j - 1] + res[i - 1 - 1][j];
            }

            res.push_back(vec);
        }

        return res;

    }
};