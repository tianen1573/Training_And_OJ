class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {

        int i = 1, j = 2, sum = 3;
        vector<vector<int>> ans;

        while(i < j && j <= target)
        {
            if(sum == target)
            {
                vector<int> arr;
                for(int k = i; k <= j; ++ k)
                    arr.push_back(k);
                ans.push_back(arr);

                ++ j;
                sum += j;
            }
            else if(sum > target)
            {
                sum -= i;
                ++ i;
            }
            else
            {
                ++ j;
                sum += j;
            }
        }

        return ans;

    }
};