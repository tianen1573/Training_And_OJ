class Solution {
public:

    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.empty()) return "";

        int len = 0;
        bool flag = true;
        while(flag)
        {
            for(auto & str : strs)
                if(len >= str.size() || str[len] != strs[0][len])
                {
                    flag = false;
                    break;
                }
            
            ++ len;
            
        }

        return strs[0].substr(0, len-1);
    }
};