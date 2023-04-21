class Solution {
public:
    int sumNums(int n) {

        (n > 1) && (n += sumNums(n - 1));

        return n;

    }
};