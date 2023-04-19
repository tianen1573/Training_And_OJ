class Solution {
public:

    string minNumber(vector<int>& nums) {

        vector<string> strs;
        for(auto val : nums)
            strs.push_back(to_string(val));
        
        sort(strs.begin(), strs.end(), [&](string a, string b)
        {
            return a + b < b + a;
        });

        string ans;

        for(auto str : strs)
            ans += str;

        return ans;
    }
};