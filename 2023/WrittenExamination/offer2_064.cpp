class MagicDictionary {
private:
    vector<string> hash;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {}
    
    void buildDict(vector<string> dictionary) {

        hash = dictionary;

    }
    
    bool search(string searchWord) {

        for(auto & str : hash)
        {
            if(str.size() != searchWord.size())
                continue;
            
            int diff = 0;

            for(int i = 0; i < str.size() && diff < 2; ++ i)
                if(str[i] != searchWord[i])
                    diff ++;
            
            if(1 == diff)
                return true;
        }

        return false;

    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */

// class MagicDictionary {
// private:
//     int idx = 0; // 分配节点
//     vector<vector<int>> trie; // 模拟树结构 -- 不完全分配
//     vector<bool> st; // 判断是否存在
// public:
//     /** Initialize your data structure here. */
//     MagicDictionary() 
//     {
//         trie.push_back(vector<int>(26, 0)); // 第0个字符
//         st.push_back(false); // 第0个字符 是否存在
//     }
    
//     void buildDict(vector<string> dictionary) {
        
//         for(auto & word : dictionary)
//         {
//             int p = 0;
//             for(int i = 0; i < word.size(); ++ i)
//             {
//                 int u = word[i] - 'a';
//                 if(!trie[p][u])
//                 {
//                     // 此时 代表当前字符在书中不存在， 进行插入
//                     trie[p][u] = ++ idx;
//                     trie.push_back(vector<int>(26, 0));
//                     st.push_back(false);
//                 }
//                 p = trie[p][u];
//             }
//             // 该字符串可能是某个字符串的前缀，仅仅靠p是否为0，无法判断字符串是否存在
//             // 该字符串为真
//             st[p] = true;
//         }

//     }
    
//     bool dfsSearch(const string& searchWord, int pos, int idx, bool flag)
//     {
//         // 必须更改一个字符 + 是否存在idx结尾的字符
//         if(pos == searchWord.size())
//             return !flag && st[idx];

//         int u = searchWord[pos] - 'a';
        
//         // 存不存在指的是 searchWord[0 ~ pos]前缀 是否在trie中存在

//         // 不存在且不能更改，则一定不符合
//         if(!trie[idx][u] && !flag)
//             return false;
        
//         // u -> i
//         for(int i = 0; i < 26; ++ i)
//         {
//             if(!trie[idx][i]) continue;

//             int newIdx = trie[idx][i];
//             if(i == u) // 存在
//             {
//                 if(dfsSearch(searchWord, pos + 1, newIdx, flag))
//                     return true;
//             }
//             else if(flag) // 不存在，但能更改 
//             {
//                 if(dfsSearch(searchWord, pos + 1, newIdx, false))
//                     return true;
//             }
//         }
//         return false;
//     }

//     bool search(string searchWord) {

//         return dfsSearch(searchWord, 0, 0, true);
//     }
// };

// /**
//  * Your MagicDictionary object will be instantiated and called as such:
//  * MagicDictionary* obj = new MagicDictionary();
//  * obj->buildDict(dictionary);
//  * bool param_2 = obj->search(searchWord);
//  */
