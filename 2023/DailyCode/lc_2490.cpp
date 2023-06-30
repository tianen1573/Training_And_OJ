class Solution {
public:
    bool isCircularSentence(string sentence) {
        
        string str[511];
        stringstream ss; ss << sentence;
        int n = 0;
        while(ss)
            ss >> str[n ++];
        -- n;
        // cout << n << endl;
        // for(int i = 0; i <= n; ++ i) cout << str[i] << endl;
        bool flag;
        if(str[n - 1][str[n - 1].size() - 1] == str[0][0]) flag = true;
        else flag = false;
        int i = 1;
        while(flag && i < n)
        {
            if(str[i - 1][str[i - 1].size() - 1] != str[i][0]) flag = false;
            ++ i;
        }


        return flag;
    }
};