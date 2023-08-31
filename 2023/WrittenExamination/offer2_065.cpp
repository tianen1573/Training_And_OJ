class Solution {
public:

    int _set(const vector<string> &words)
    {
        unordered_set<string> hash(words.begin(), words.end());

        // 遍历words，因为遍历hash可能会导致迭代器失效
        for(const auto& str : words)
        {
            for(int i = 1; i < str.size(); ++ i)
            {
                hash.erase(str.substr(i));
            }
        }

        int ans = 0;
        for(auto & str : hash)
            ans += str.size() + 1;
        return ans;
    }
    void _dfsTrie(vector<vector<int>> &trie, int p, int len, int &sum)
    {
        bool flag = true;
        for(int i = 0; i < 26; ++ i)
        {
            if(trie[p][i])
            {
                _dfsTrie(trie, trie[p][i], len + 1, sum);
                flag = false;
            }
        }

        if(flag)
            sum += len + 1;
    }
    int _trie(const vector<string> &words)
    {
        vector<vector<int>> trie;
        trie.push_back(vector<int>(26, 0));

        for(auto str : words)
        {
            reverse(str.begin(), str.end());

            int p = 0;
            for(int i = 0; i < str.size(); ++ i)
            {
                int u = str[i] - 'a';
                if(!trie[p][u])
                {
                    trie[p][u] = trie.size();
                    trie.push_back(vector<int>(26, 0));
                }
                p = trie[p][u];
            }
        }

        int ans = 0;
        for(int i = 0; i < 26; ++ i)
            if(trie[0][i])
                _dfsTrie(trie, trie[0][i], 1, ans);
        return ans;
    }
    int minimumLengthEncoding(vector<string>& words) {

        // 1. 字典树
        // a. 倒序插入字典树
        // b. 统计 叶子节点的高度 + 1
        return _trie(words);
        // 2. set
        // return _set(words);
    }
};