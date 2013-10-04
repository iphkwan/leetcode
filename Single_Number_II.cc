class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int One = 0, Two = 0, Three = 0;
        for (int i = 0; i < n; i++) {
            Two |= (One & A[i]);
            One ^= A[i];
            Three = One & Two;
            One &= (~Three);
            Two &= (~Three);
        }
        return (One | Two);
    }
};
