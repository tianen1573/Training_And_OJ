class Solution {
public:
    string replaceSpace(string s) {
        int cnt = 0;
        int oldSize = s.size();
        for(auto ch : s)
            if(' ' == ch)
                cnt++;

        s.resize(oldSize + cnt * 2);
        int newSize = s.size();

        for(int i = oldSize - 1, j = newSize - 1; i >= 0; -- i)
        {
            if(' ' == s[i])
            {
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
            }
            else
            {
                s[j--] = s[i];
            }
        }

        return s;

    }
};