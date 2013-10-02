class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ret = 0;
        for (int i = 0; i < n; i++) {
            ret ^= A[i];
        }
        return ret;
    }
};
