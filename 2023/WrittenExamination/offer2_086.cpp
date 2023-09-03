class Solution {
private:
    string str;
    vector<vector<string>> ans;
    bool nonPlalindrome(string& str)
    {
        int l = 0, r = str.size() - 1;
        while(l < r)
        {
            if(str[l] != str[r])
                return true;
            ++ l, -- r;
        }

        return false;
    }
    void sol(int idx, vector<string>& tmp)
    {
        if(idx == str.size())
        {
            ans.push_back(tmp);
            return ;
        }

        for(int i = idx; i < str.size(); ++ i)
        {
            string s = str.substr(idx, i - idx + 1);
            if(nonPlalindrome(s)) 
                continue;
            
            tmp.push_back(s);
            sol(i + 1, tmp);
            tmp.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        
        this->str = s;
        vector<string> tmp;
        sol(0, tmp);

        return ans;
    }
};