#include <algorithm>
#include <cctype>
class Solution {
public:

    string trans(string s, int n) {
        // write code here

        reverse(s.begin(), s.end());

        for(int i = 0; i < n; ++ i)
        {
            int l = i;
            while(i < n && s[i] != ' ')
                s[i++] ^= 0b100000;
            
            reverse(s.begin() + l, s.begin() + i);
        }

        return s;
    }
};