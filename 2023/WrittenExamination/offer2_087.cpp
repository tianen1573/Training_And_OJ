class Solution {
    string str;
    string IP_MAX = "255";
    vector<string> ans;
    bool myCmp(string &a, string& b)
    {
        if(a.size() != b.size())
            return a.size() > b.size();
        for(int i = 0; i < a.size(); ++ i)
        {
            if(a[i] == b[i])
                continue;
            else if(a[i] > b[i])
                return true;
            else 
                return false;
        }
        return false;
    }
    void sol(int idx, int cnt, string tmp)
    {
        if(idx > str.size() || cnt > 4 || (cnt == 4 && idx < str.size()))
            return ;
        if(idx == str.size() && cnt == 4)
        {
            tmp.pop_back(); // 去除最后一个 '.'
            ans.push_back(tmp);
            return ;
        }

        // 特殊处理'0'
        if(str[idx] == '0')
        {
            sol(idx + 1, cnt + 1, tmp + "0.");
        }
        else
        {
            for(int i = idx; i < idx + 3 && i < str.size(); ++ i)
            {
                string s = str.substr(idx, i - idx + 1);
                if(myCmp(s, IP_MAX)) // 比较对应的int大小
                    continue;
                
                sol(i + 1, cnt + 1, tmp + s + '.');
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {

        this->str = s;
        sol(0, 0, "");

        return ans;
    }
};