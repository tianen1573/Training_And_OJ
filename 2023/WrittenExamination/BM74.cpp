class Solution {
public:
    
    vector<string> ret;
    void dfs(string tmp, int pos, int cnt, const string &s)
    {
        if(pos == s.size() && cnt == 5)
        {
            ret.push_back(std::move(tmp.substr(1)));
            return ;
        }
        else if(cnt == 5)
        {
            return ;
        }

        //一位数
        dfs(tmp + '.' + s[pos], pos + 1, cnt + 1, s);
        //两位数
        if(pos + 1 < s.size() && s[pos] != '0')
            dfs(tmp + '.' + s[pos] + s[pos + 1], pos + 2, cnt + 1, s);
        //三位数
        if(pos + 2 < s.size() && s[pos] != '0')
        {
            string str = s.substr(pos, 3);
            if(str <= "255")
                dfs(tmp + '.' + str, pos + 3, cnt + 1, s);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        
        dfs("", 0, 1, s);
        return ret;
    }
};