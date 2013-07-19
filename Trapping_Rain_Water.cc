class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 2) {
            return 0;
        }
        int *lmax = new int[n];
        int *rmax = new int[n];
        int ret = 0, tmp;
        lmax[0] = A[0];
        rmax[n - 1] = A[n - 1];
        for (int i = 1; i < n - 1; i++) {
            lmax[i] = (lmax[i - 1] > A[i] ? lmax[i - 1] : A[i]);
            rmax[n - 1 - i] = (rmax[n - i] > A[n - 1 - i] ? rmax[n - i] : A[n - 1 - i]);
        }
        for (int i = 1; i < n - 1; i++) {
            tmp = (lmax[i] < rmax[i] ? lmax[i] : rmax[i]);
            if (tmp > A[i]) {
                ret += (tmp - A[i]);
            }
        }
        delete [] lmax;
        delete [] rmax;
        return ret;
    }
};