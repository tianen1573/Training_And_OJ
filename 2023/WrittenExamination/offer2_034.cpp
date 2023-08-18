class Solution {
public:
    bool mySort(string &a, string &b, unordered_map<char, int> &hash)
    {
        for(int i = 0; i < a.size() && i < b.size(); ++ i)
        {
            if(hash[a[i]] < hash[b[i]])
                return true;
            else if(hash[a[i]] > hash[b[i]])
                return false;
        }
        return a.size() <= b.size();
    }
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> hash;
        for(int i = 0; i < 26; ++ i)
            hash[order[i]] = i;
        
        for(int i = 1; i < words.size(); ++ i)
        {
            if(mySort(words[i - 1], words[i], hash) == false)
                return false;
        }

        return true;
    }
};