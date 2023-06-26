class Solution {
public:
    int qSort(vector<int>& arr, int l, int r, int k)
    {
        int i = l, j = r;
        int val = arr[l];

        while(i < j)
        {
            while(i < j && arr[j] <= val) -- j;
            while(i < j && arr[i] >= val) ++ i;
            swap(arr[i], arr[j]);
        }
        swap(arr[i], arr[l]);
        
        if(i == k) return arr[k];
        if(i > k) return qSort(arr, l, i - 1, k);
        else return qSort(arr, i + 1, r, k);
    }
    int findKth(vector<int> arr, int n, int K) {
        // write code here

        return qSort(arr, 0, arr.size() - 1, K - 1);
    }
};