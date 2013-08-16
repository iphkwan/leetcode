class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int cur = m + n - 1;
        m--, n--;
        while (m >= 0 && n >= 0) {
            if (A[m] > B[n])    A[cur--] = A[m--];
            else    A[cur--] = B[n--];
        }
        while (n >= 0)  A[cur--] = B[n--];
    }
};
