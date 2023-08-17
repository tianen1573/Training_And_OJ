class RandomizedSet {
private:
    vector<int> arr;
    unordered_map<int, int> hash;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand((unsigned)time(nullptr));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hash.count(val) != 0)
        {
            return false;
        }

        int last = arr.size();
        arr.emplace_back(val);
        hash[val] = last;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(hash.count(val) == 0)
        {
            return false;
        }

         int idx = hash[val];
         int lastVal = arr.back();
         arr[idx] = lastVal;
         hash[lastVal] = idx;
         arr.pop_back();
         hash.erase(val);
         return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {

        int randIdx = rand() % arr.size();
        return arr[randIdx];

    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */