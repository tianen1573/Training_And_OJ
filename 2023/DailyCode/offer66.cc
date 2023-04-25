class Solution {
public:
    vector<int> constructArr(vector<int>& arr) {

        vector<int> leftArr(arr.size() + 2), rigArr(arr.size() + 2);
        leftArr[0] = leftArr[arr.size() + 1] = rigArr[0] = rigArr[arr.size() + 1] = 1;

        for(int i = 1; i <= arr.size(); ++ i)
            leftArr[i] = leftArr[i - 1] * arr[i - 1];
        for(int j = arr.size(); j >= 1; -- j)
            rigArr[j] = rigArr[j + 1] * arr[j - 1]; 

        vector<int> ret;
        for(int i = 0, j = 2; i < arr.size(); ++ i, ++ j)
            ret.push_back(leftArr[i] * rigArr[j]);

        return ret;

    }
};