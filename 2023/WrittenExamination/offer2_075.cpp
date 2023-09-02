class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        unordered_map<int, int> hash;
        int len = arr2.size();
        for(int i = 0; i < len; ++ i)
        {
            // map中不存在的变量使用[]时
            // 会调用插入并默认赋值一个0
            // 根据这个原理
            // 使arr2对应的下标越靠前，val越小
            // 从而实现升序
            hash[arr2[i]] = -(len - i + 1);
        }

        vector<int> tmp(arr1);
        sort(tmp.begin(), tmp.end(), [&](auto &a, auto &b)
        {
            if(hash[a] != hash[b]) 
                return hash[a] < hash[b];
            return a < b;
        });

        return tmp;
    }
};