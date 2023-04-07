class Solution {
public:
    char firstUniqChar(string s) {

        vector<int> vec(26, -1);

        for(int i = 0; i < s.size(); ++ i)
        {
            int pos = s[i] - 'a';
            if(vec[pos] == -1)//第一次出现
            {
                vec[pos] = i;
            }
            else if(vec[pos] != -2)//多次出现
            {
                vec[pos] = -2;
            }
        }

        int ret = INT_MAX, pos = -1;
        for(int i = 0; i < 26; ++ i)
        {
            if(vec[i] == -1 || vec[i] == -2) continue;

            if(ret > vec[i])
            {
                ret = vec[i];
                pos = i;
            }
        }
        

        return pos == - 1 ? ' ' : 'a' + pos;
    }
};