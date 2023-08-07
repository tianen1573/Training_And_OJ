class Solution {
public:
    void _reverse(int l, int r, vector<int>& arr)
    {
        while(l < r)
        {
            swap(arr[l], arr[r]);
            ++ l;
            -- r;
        }
    }
    vector<int> solve(int n, int m, vector<int>& arr) {
        
        m = m % n;
        _reverse(0, n - 1, arr);
        _reverse(0, m - 1, arr);
        _reverse(m, n - 1, arr);

        return arr;
    }
};