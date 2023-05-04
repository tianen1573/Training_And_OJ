class Solution {
public:
    vector<int> printNumbers(int n) {

        int value = 1;
        while(n)
        {
            value *= 10;
            n--;
        }
        value;

        vector<int> vec;
        for(int i = 1; i < value; ++ i)
            vec.push_back(i);

        return vec;
    }
};