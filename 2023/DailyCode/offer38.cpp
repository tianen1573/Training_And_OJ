class Solution {
public:

    void dfs(string str, int len)
    {
        if(len == LEN)
        {
            res.push_back(str);
            return ;
        } 

        //剪枝
        //在一个特定的位置，某个元素只允许出现一次
        set<int> SET;
        for(int i = 0; i < LEN; ++ i)
        {
            if(Bit.test(i)) continue;

            if(SET.find(STR[i]) != SET.end()) continue;//该位置曾经出现过，不允许再出现
            else
            {
                SET.insert(STR[i]);//保存
                Bit.set(i);               
                dfs(str + STR[i], len + 1);
                Bit.reset(i);
            }
        }
        
    }
    vector<string> permutation(string str) {

        bitset<16> tmp(str.size());
        Bit = tmp;
        Bit.reset();
        STR = str;
        LEN = str.size();

        dfs("", 0);

        return res;

    }

    bitset<16> Bit;
    vector<string> res;
    string STR;
    int LEN;
};