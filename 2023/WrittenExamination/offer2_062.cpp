class Trie {
public:
    /** Initialize your data structure here. */
    int idx = 0; // 分配节点
    vector<vector<int>> trie; // 模拟树结构 -- 不完全分配 
    vector<bool> st; // 判断是否存在
    Trie() {
        trie.push_back(vector<int>(26, 0)); // 第0个字符
        st.push_back(false); // 第0个字符 是否存在
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {

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
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int p = 0;
        for(int i = 0; i < word.size(); ++ i)
        {
            int u = word[i] - 'a';
            if(!trie[p][u]) return false;
            p = trie[p][u];
        }

        return st[p];
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int p = 0;
        for(int i = 0; i < prefix.size(); ++ i)
        {
            int u = prefix[i] - 'a';
            if(!trie[p][u]) return false;
            p = trie[p][u];
        }

        // p不为0，则一定存在该字符串
        return p;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */