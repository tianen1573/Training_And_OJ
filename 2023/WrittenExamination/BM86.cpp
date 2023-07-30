class Solution {
public:
    
    string solve(string s, string t) {
        
        int i = s.size() - 1, j = t.size() - 1;
        int cry = 0;
        string retString;
        while(i >= 0 && j >= 0)
        {
            cry += (s[i --] + t[j --] - '0' - '0');
            retString.push_back(cry % 10 + '0');
            cry /= 10;
        }
        while(i >= 0)
        {
            cry += s[i --] - '0';
            retString.push_back(cry % 10 + '0');
            cry /= 10;
        }
        while(j >= 0)
        {
            cry += t[j --] - '0';
            retString.push_back(cry % 10 + '0');
            cry /= 10;
        }
        while(cry > 0)
        {
            retString.push_back(cry % 10 + '0');
            cry /= 10;
        }

        reverse(retString.begin(), retString.end());

        return retString;
    }
};