class Solution {
public:
    int singleNumber(int A[], int n) {
        sort(A, A+n);
        for(int i=0; i<n-1; i+=2) {
            if(A[i] != A[i+1])
                return A[i];
        }
        return A[n-1];
    }
};