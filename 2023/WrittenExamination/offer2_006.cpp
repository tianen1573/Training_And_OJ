class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int l = 0, r = numbers.size() - 1;
        while(l < r)
        {
            if(numbers[l] + numbers[r] == target)
            {
                return vector<int>() = {l, r};
            }
            else if(numbers[l] + numbers[r] > target)
                -- r;
            else 
                ++ l;
        }

        return vector<int>();
    }
};