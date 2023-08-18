class Solution {
public:
    bool isAnagram(string s, string t) {
        
        // 排序 nlogn
        if(s == t) return false;
        if(s.size() != t.size()) return false;   

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s == t;

        //哈希表 n 和 n
    }
};