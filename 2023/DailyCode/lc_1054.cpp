// class str{
// public:
//     str(int l, int v)
//     {
//         val = v;
//         len = l;
//     }

//     int val, len;

//     bool operator< (const str& t) const
//     {
//         if(len != t.len) return len < t.len;
//         else return val < t.val;
//     }
// };//使用pair

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {

        priority_queue<pair<int, int>> heap;//记录剩下的元素值及个数
        unordered_map<int, int> mii;//统计个数

        for(auto val : barcodes)
            mii[val]++;
        for(auto t : mii)
            heap.push({t.second, t.first});

        vector<int> ans;
        pair<int, int> last = {0,0};//延迟放入
        while(heap.size())
        {
            auto t = heap.top();
            heap.pop();

            ans.push_back(t.second);
            
            //这次取出的元素，下一个回合再放
            //如果上一次取出的元素还有剩余，则放入
            if(last.first) heap.push(last);
            
            --t.first;
            last = t;

        }
        return ans;

    }
};