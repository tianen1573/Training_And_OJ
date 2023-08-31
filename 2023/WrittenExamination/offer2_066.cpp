class MapSum {

private:

    unordered_map<string, int> hash;

public:
    /** Initialize your data structure here. */
    MapSum() 
    {
        // 字典树，找到prefix最后一个字符所在的节点
        // 然后遍历该节点的所有后续叶子节点
        // 期间需要记录字符串

        // 我选择暴力
    }
    
    void insert(string key, int val) {

        hash[key] = val;
    }
    
    int sum(string prefix) {

        int ans = 0;

        for(auto &[key, val] : hash)
        {
            if(key.find(prefix) == 0)
                ans += val;
        }

        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */