class Solution {
public:
    bool isPalindrome(string s) {
        
        string str;
        for(auto ch : s)
        {
            if(!isalnum(ch)) continue;
            if(isalpha(ch)) ch |= 0b100000;
            str += ch;
        }

        int l = 0, r = str.size() - 1;
        while(l < r)
        {
            if(str[l] != str[r]) return false;

            ++ l;
            -- r;
        }

        return true;
    }
};