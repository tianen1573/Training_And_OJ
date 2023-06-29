class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {

        vector<int> up, low;

        for(auto t : colsum)
        {
            if(upper < 0 || lower < 0) return vector<vector<int>>();

            if(t == 0)
            {
                up.push_back(0), low.push_back(0);
            }
            else if(t == 2)
            {
                -- upper, -- lower;
                up.push_back(1), low.push_back(1);    
            }
            else 
            {
                if(upper >= lower) 
                {
                    -- upper;
                    up.push_back(1), low.push_back(0);
                }
                else
                {
                    -- lower;
                    up.push_back(0), low.push_back(1);
                }
            }
        }

        if(upper == 0 && lower == 0) return vector<vector<int>>() = {up, low};
        return vector<vector<int>>(); 
    }
};