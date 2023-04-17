class Solution {
public:
    int lengthOfLongestSubstring(string str) {

        // if(str.empty()) return 0;

        // vector<int> pos(128, -1);
        // int begin = 0, cnt = 1;

        // for(int i = 0; i < str.size(); ++ i)
        // {
        //     if(pos[str[i]] >= begin)
        //     {
        //         begin = pos[str[i]] + 1;
        //     }

        //     cnt = max(cnt, i - begin + 1);
        //     pos[str[i]] = i;
        // }


        // return cnt;

        int len = str.size(), cnt = 0, left = 0;

        unordered_map<char, int> mci;

        for(int i = 0; i < len; ++ i)
        {
            ++ mci[str[i]];

            while(mci[str[i]] > 1)
                -- mci[str[left++]];

            cnt = max(cnt, i - left + 1);
        }

        return cnt;
    }
};