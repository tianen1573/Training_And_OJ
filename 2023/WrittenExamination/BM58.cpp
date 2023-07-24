class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @return string字符串vector
     */
    bool st[11] = {0};
    vector<string> res;
    unordered_set<string> hash;

    void Permutations(string tmp, const string &str)
    {
        bool flag = true;
        for(int i = 0; i < str.size(); ++ i)
        {
            if(st[i]) continue;

            flag = false;
            st[i] = true;
            Permutations(tmp + str[i], str);
            st[i] = false;
        }

        if(flag && hash.find(tmp) == hash.end())
        {
            hash.insert(tmp);
            res.push_back(std::move(tmp));
        }
    }

    vector<string> Permutation(string str) {

        Permutations(string(), str);

        return res;

    }
};