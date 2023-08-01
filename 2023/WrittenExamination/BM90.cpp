#include <unordered_map>
class Solution {
public:

    string minWindow(string S, string T) {
        
        // 处理T
        unordered_map<char, int> hash;
        for(auto ch : T)
            ++ hash[ch];
        int diff = hash.size();
        queue<char> que;

        // 开滑
        int ret = 0x3f3f3f3f;
        string retString = "";
        for(int i = 0; i < S.size(); ++ i)
        {
            // 入队
            que.push(S[i]);
            // 非T元素不关心
            if(hash.find(S[i]) == hash.end()) continue;
            // T元素引起diff变化
            if(-- hash[S[i] == 0]) -- diff;

            // 队内元素含有T
            // 开滑，滑到不含T
            if(diff == 0)
            {
                // 合法字串左边可能存在其他字符
                // 所以我们需要先左缩，将合法字串缩到最小，即diff != 0
                // 压缩至左端点diff != 0
                while(que.size())
                {
                    char head = que.front();
                    que.pop();
                    if(hash.find(head) != hash.end()) continue; // 非T元素不关心
                    // 队里的T元素可能过多，出队时不一定引起diff变化
                    // 引起diff变化
                    if( ++ hash[head] == 1)
                    {
                        ++ diff;
                        // 更新ret
                        if(que.size() + 1 < ret) //此时左端点刚划走了t的元素，需要捡回来
                        {
                            ret = que.size() + 1;
                            retString = S.substr(i-ret+1, ret);
                        }
                        // 把两个T元素之间的无关元素滑走
                        while(que.size())
                            if(hash.find(que.front()) == hash.end()) que.pop();
                            else break;
                        
                        break;
                    }
                }
            }
        }

        return retString;
    }
};