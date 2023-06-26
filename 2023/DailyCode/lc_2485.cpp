class Solution {
public:
    int pivotInteger(int n) {
        
        int sum = n * n + n;
        if(sum % 2) return -1;
        else sum /= 2;

        int x = (int)sqrt(sum);
        if(x * x == sum) return x;
        else return -1;

    }
};
