class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {

        unordered_map<int, int> hash;
        for(int i = 0; i < arr.size(); ++ i)
            hash[arr[i]] = i;
        vector<int> f(arr.size(), 0);
        int ret = 0;
        for(int i = 0; i < arr.size(); ++ i)
        {
            for(int j = i + 1; j < arr.size(); ++ j)
            {
                int len = 3;
                int a = arr[i];
                int b = arr[j];
                while(true)
                {
                    int val = a + b;
                    if(hash.count(val) == 0)
                        break;

                    ret = max(ret, len);

                    int idx = hash[val];
                    f[idx] = max(f[idx], len);

                    a = b;
                    b = val;
                    ++ len;
                }
            }
        }
        
        return ret;
    }
};