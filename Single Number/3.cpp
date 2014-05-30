class Solution {
public:
    int singleNumber(int A[], int n) {
        while(--n != 0)
        	A[n-1] ^= A[n];
        return A[0];
    }
};