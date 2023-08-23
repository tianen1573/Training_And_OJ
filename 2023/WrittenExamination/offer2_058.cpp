class MyCalendar {
public:

    set<pair<int, int> > hash;
    MyCalendar() {}
    
    // [s1, e1) [start, end) [s2, e2)
    // start >= e1 && s2 >= end
    bool book(int start, int end) {
        
        // 1. 查找 [s2, e2)
        auto iter = hash.lower_bound({end, 0});
        // 此时 s2 >= end，判断是否满足 start >= e1
        if(iter == hash.begin() || (-- iter)->second <= start)
        {
            hash.insert({start, end});
            return true;
        }

        return false;
    }
};
