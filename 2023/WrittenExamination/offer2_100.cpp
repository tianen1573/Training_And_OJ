class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        for(int i = 1; i < triangle.size(); ++ i)
        {
            triangle[i][0] += triangle[i - 1][0]; // 特殊处理第一个
            for(int j = 1; j < triangle[i].size() - 1; ++ j)
                triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
            triangle[i][triangle[i].size() - 1] += triangle[i - 1][triangle[i].size() - 2]; // 特殊处理最后一个
        }
        int minVal = INT_MAX;
        for(int i = 0; i < triangle[triangle.size() - 1].size(); ++ i)
        {
            minVal = min(minVal, triangle[triangle.size() - 1][i]);
        }
        return minVal;
    }
};