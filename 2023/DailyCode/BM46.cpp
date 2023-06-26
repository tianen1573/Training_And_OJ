class Solution {
public:

    vector<int> qSort(vector<int> &vec, int l, int r, int k)
    {
        int i = l, j = r;
        
        int val = vec[l];

        while(i < j)
        {
            while(i < j && val <= vec[j]) -- j;
            while(i < j && val >= vec[i]) ++ i;

            swap(vec[i], vec[j]);
        }
        swap(vec[i], vec[l]);

        if(i == k) return vector<int>(vec.begin(), vec.begin() + k);
        else if(i < k) return qSort(vec, i + 1, r, k);
        else return qSort(vec, l, i - 1, k);
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        
        if(k >= input.size()) return input;
        return qSort(input, 0, input.size() - 1, k);
    }
};