class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        unordered_map<string, int> hash;
        for(auto &str : strs)
        {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            if(hash.count(tmp) == 0)
            {
                int idx = ans.size();
                ans.push_back({str});
                hash[tmp] = idx;
            }
            else
            {
                int idx = hash[tmp];
                ans[idx].push_back(str);
            }
        }

        return ans;
    }
};