class Solution {
public:
    int maxProduct(vector<string>& words) {
        //只包含小写字符，26个，需要判断字符串是否存在相同字符，32位int即可以存储26个标识，相与也能快速判断是否存在相同字符
        //n=1000，可以n^2暴力匹配，优化的话感觉可以把字符串长度排序，从高到低匹配，本质还是n^2

        int res = 0;
        vector<int> hash;
        
        for(auto &str : words)
        {
            int val = 0;

            for(char c : str)
                val |= (1 << (c - 'a'));

            hash.push_back(val);
        }

        for(int i = 0; i < words.size(); ++ i)
            for(int j = i + 1; j < words.size(); ++ j)
            {
                if(hash[i] & hash[j]) continue;

                int l1 = words[i].size(), l2 = words[j].size();
                res = max(res, l1 * l2);
            }
        
        return res;

    }
};