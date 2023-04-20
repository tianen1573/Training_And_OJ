class Solution {
public:

    vector<int> qSort(vector<int> &arr, int l, int r, int k)
    {
        int i = l, j = r;

        int val = arr[l];

        while(i < j)
        {
            while(i < j && arr[j] >= val) -- j;
            while(i < j && arr[i] <= val) ++ i;

            swap(arr[i], arr[j]);
        }

        swap(arr[i], arr[l]);

        if(i == k) return vector<int>(arr.begin(), arr.begin() + k);
        else if(i > k) return qSort(arr, l, i - 1, k);
        return qSort(arr, i + 1, r, k);
    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {

        if(k >= arr.size()) return arr;

        return qSort(arr, 0, arr.size() - 1, k);
    }
};