class Solution {
public:
    string reverseLeftWords(string s, int n) {

        string left = s.substr(0, n);
        string right = s.substr(n);

        s = right + left;

        return s;

    }
};
//原地翻转三次