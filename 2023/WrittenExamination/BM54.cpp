class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param num int整型vector 
     * @return int整型vector<vector<>>
     */
    int binary(int l, int r, int val, vector<int> &vec)
    {
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(vec[mid] >= val) r = mid;
            else l = mid + 1;
        }

        if(vec[l] == val) return l;
        else return -1;
    }
    vector<vector<int> > threeSum(vector<int>& num) {

        typedef pair<int, pair<int, int>> iii;
        set<iii> hash;

        sort(num.begin(), num.end());
        // num.erase(unique(num.begin(), num.end()), num.end());
        int n = num.size();
        for(int i = 0; i < n - 2; ++ i)
        {
            if(num[i] > 0) break;
            for(int j = i + 1; j < n - 1; ++ j)
            {
                if(num[i] + num[j] > 0) break;
                int k = binary(j + 1, n - 1, 0 - num[i] - num[j], num);
                if(k != -1)
                {
                    iii tmp = {num[i], {num[j], num[k]}};
                    hash.insert(tmp);
                }
            }
        }

        vector<vector<int> > res;
        for(auto &t : hash)
        {
            res.push_back({t.first, t.second.first, t.second.second});
        }
        return res;
    }
};