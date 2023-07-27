class Solution {
public:
    int lengthOfLongestSubstring(string str) {

        //滑动窗口+hash
        //每次元素入队时，hash++；出队时，hash--
        //我们维持队列里没有重复元素，则仅仅入队的元素可能造成队列存在重复元素
        //遍历出队，直至队列合法
        queue<char> que;
        unordered_map<char, int> hash;
        int ret = 0;
        for(auto ch : str)
        {
            que.push(ch);
            ++ hash[ch];

            while(hash[ch] > 1)
            {
                -- hash[que.front()];
                que.pop();
            }
            if(que.size() > ret)
                ret = que.size();
        }

        return ret;
    }
};