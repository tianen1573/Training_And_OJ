class Solution {
public:
    string itoa(int num)
    {
        string tmp;
        for(int i = 0; num && i < 32; ++ i)
        {
            tmp += (num & 1) + '0';
            num >>= 1;
        }
        reverse(tmp.begin(), tmp.end());
        return tmp;
    }
    bool queryString(string s, int n) {

        // //1. 将字符串转成成数字
        
        // unordered_set<int> uset;
        // uset.insert(0);

        // for(int i = 0; i < s.size(); ++ i)
        // {
        //     int val = 0;
        //     for(int j = i; j < s.size(); ++ j)
        //     {
        //         val = val * 2 + s[j] - '0';
        //         if(val <= n) uset.insert(val);
        //         else break;
        //     }
        // }

        // for(auto v : uset)
        //     cout << v << ' ';

        // return uset.size() == n + 1;


        //2. 将1~n转换成字符串，进行字符串匹配

        

        vector<string> vec;
        for(int i = 1; i <= n; ++ i)
        {
            string tmp = itoa(i);
            if(s.find(tmp) == string::npos) return false;
        }
        
        //超时。。。。
        // for(auto & str : vec)
        // {
        //     if(s.find(str) == string::npos) return false;
        // }

        return true;
    }
};