class Solution {
public:
    int countSubstrings(string str) {

        // dp 两边到中心 N^2
        bool f[1011][1011] = {false};
        for(int i = 0; i <= str.size(); ++ i)
            f[i][i] = true;
        
        int ret = str.size();
        for(int len = 2; len <= str.size(); ++ len)
            for(int i = 0; i + len - 1 < str.size(); ++ i)
            {
                int j = i + len - 1;
                if(str[i] != str[j]) continue;

                if(len == 2) f[i][j] = true;
                else f[i][j] = f[i+1][j-1];

                if(f[i][j]) ++ ret;
            }
        
        return ret;
    }
};