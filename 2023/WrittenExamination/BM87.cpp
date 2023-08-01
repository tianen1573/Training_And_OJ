class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        
        int r = m + n - 1;
        int i = m - 1, j = n - 1;

        cout << m << ' ' << n;
        while(i >= 0 && j >= 0)
        {
            if(A[i] > B[j])
                A[r --] = A[i --];
            else
                A[r --] = B[j --];
        }
        while(i >= 0)
        {
            A[r --] = A[i --];
        }
        while(j >= 0)
        {
            A[r --] = B[j --];
        }
    }
};