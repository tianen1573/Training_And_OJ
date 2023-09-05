class Solution {
public:
    int numDistinct(string s, string t) {
        
        // // hash 用来存储t中字符对应的下标idx
        // // cnt 用来存储t中对应下标在遍历到i时的序列(0~idx)数
        // // 当t中有重复字符时，我们把后面的放在前面，即保证下标是降序的
        // // 这样，在遇到bbbbb时，先统计后面的不会影响前面的，反之，则会影响
        // unordered_map<char, vector<int>> hash;
        // unordered_map<int, unsigned int> cnt;
        // for(int i = 0; i < t.size(); ++ i)
        // {
        //     // 存储下标 和 个数
        //     hash[t[i]].push_back(i);
        //     cnt[i] = 0;
        // }
        // for(auto &[x, arr] : hash)
        // {
        //     // 降序
        //     reverse(arr.begin(), arr.end());
        // }
        // for(int i = 0; i < s.size(); ++ i)
        // {
        //     // 在t中不存在
        //     if(hash.count(s[i]) == 0)
        //         continue;
        //     // 遍历s[i]在t中的下标
        //     const vector<int>& idxArr = hash[s[i]];
        //     for(auto idx : idxArr)
        //     {
        //         // 是t的第一个元素
        //         if(idx == 0)
        //         {
        //             ++ cnt[idx];
        //         }
        //         else
        //         {
        //             // 找到前一个
        //             int pre = idx - 1;
        //             // 直接加上
        //             cnt[idx] += cnt[pre]; 
        //             // 题目数据保证答案符合 32 位带符号整数范围。shabi
        //         }
        //     } 
        // }

        // // 最后一个元素
        // return cnt[t.size() - 1];

        /*DP*/
        int n = s.size(), m = t.size();
        // f[i][j]：s的前i个，构成t的前j个 的 个数
        // vector<vector<unsigned int>> f(n + 1, vector<unsigned int>(m + 1, 0));
        // 滚动数组
        vector<unsigned int> f(m + 1, 0);
        for(int i = 0; i < n; ++ i)
            f[0] = 1;
        for(int i = 1; i <= n; ++ i)
        {
            for(int j = m; j >= 1; -- j)
            {
                if(s[i - 1] == t[j - 1])
                    f[j] += f[j - 1];
            }
        }

        return f[m];

    }
};