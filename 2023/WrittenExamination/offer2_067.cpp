class Solution {

private:
    vector<vector<int>> trie;

    void insert(int val)
    {
        int p = 0;
        for(int i = 30; i >= 0; -- i)
        {
            if(trie[p][(val >> i) & 1] == 0)
            {
                trie.emplace_back(vector<int>(2,0));
                trie[p][(val >> i) & 1] = trie.size() - 1;
            }
            p = trie[p][(val >> i) & 1];
        }
    }
    int search(int val)
    {
        int p = 0, res = 0;
        for(int i = 30; i >= 0; -- i)
        {
            int u = (val >> i) & 1;
            if(trie[p][!u])
            {
                res += (1 << i);
                p = trie[p][!u];
            }
            else
                p = trie[p][u];
        }

        return res;
    }

public:
    int findMaximumXOR(vector<int>& nums) {
        trie.emplace_back(vector<int>(2,0));
        int res = 0;

        for(auto val : nums)
        {
            // 先查
            res = max(res, search(val));
            // 后入
            insert(val);
        }

        return res;

    }
};