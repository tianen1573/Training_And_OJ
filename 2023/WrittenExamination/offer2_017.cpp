class Solution {
public:
    string minWindow(string s, string t) {
        // 先统计t的字典集，和差diff
        unordered_map<char, int> hash;
        for(auto ch : t)
            ++ hash[ch];
        int diff = hash.size();
        queue<char> que;

        // 开滑
        int ret = 0x3f3f3f3f;
        string retString = "";
        for(int i = 0; i < s.size(); ++ i)
        {
            // 入队
            que.push(s[i]);
            // 非t的元素不关心
            if(hash.find(s[i]) == hash.end()) continue;

            // 引起diff变化
            if(-- hash[s[i]] == 0) -- diff;

            // 滑动窗口里存在t
            if(diff == 0)
            {
                // 压缩左端点至diff!=0
                while(que.size())
                {

                    char head = que.front();
                    que.pop();
                    if(hash.find(head) == hash.end()) continue; // 非t的元素不关心
                    // 引起diff变化
                    if(++ hash[head] == 1)
                    {
                        ++ diff;
                        // 更新ret
                        if(que.size() + 1 < ret) //此时左端点刚划走了t的元素，需要捡回来
                        {
                            ret = que.size() + 1;
                            retString = s.substr(i-ret+1, ret);
                        }

                        // 把两个t直接的无关元素滑走
                        while(que.size())
                            if(hash.find(que.front()) == hash.end()) // 可以将条件改成t元素变小，多滑几次
                                que.pop();
                            else
                                break;
                        break;
                    }
                }
            }
        }

        return retString;
    }
};