class Solution {
public:

    int idx = 0; // 分配节点
    vector<vector<int>> trie; // 模拟树结构 -- 不完全分配
    vector<bool> st; // 判断是否存在

    void insert(const string &word) 
    {

        trie.push_back(vector<int>(26, 0)); // 第0个字符
        st.push_back(false); // 第0个字符 是否存在

        int p = 0;
        for(int i = 0; i < word.size(); ++ i)
        {
            int u = word[i] - 'a';
            if(!trie[p][u])
            {
                // 此时 代表当前字符在书中不存在， 进行插入
                trie[p][u] = ++ idx;
                trie.push_back(vector<int>(26, 0));
                st.push_back(false);
            }
            p = trie[p][u];
        }

        // 该字符串可能是某个字符串的前缀，仅仅靠p是否为0，无法判断字符串是否存在
        // 该字符串为真
        st[p] = true;
        
    }
    int startsWith(const string &prefix) { // 返回的是prefix的前缀长度
        
        int p = 0;
        int i = 0;
    
        for(; i < prefix.size(); ++ i)
        {
            int u = prefix[i] - 'a';
            if(!trie[p][u]) return prefix.size() - 1;

            p = trie[p][u];
            if(st[p]) return i;
        }

        return prefix.size() - 1;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        // 构建字典树
        for(auto &str : dictionary)
            insert(str);

        // 分割字符串
        vector<string> strs;
        int cur = 0;
        while(cur < sentence.size())
        {
            int pos = sentence.find(' ', cur);
            if(pos == string::npos)
                pos = sentence.size();

            strs.push_back(sentence.substr(cur, pos - cur));

            cur = pos + 1; 
        }
        
        // 构建字符串
        string ret;
        for(auto &str : strs)
        {
            ret += str.substr(0, startsWith(str) - 0 + 1) + ' ';
        }
        ret.pop_back(); // 取出空格

        return ret;

    }
};