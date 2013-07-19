class Solution {
public:
    double solve(int A[], int m, int B[], int n, int TopK) {
        if (m > n) {
            return solve(B, n, A, m, TopK);
        }
        if (m == 0) {
            return (double)(B[TopK - 1]);
        }
        if (TopK == 1) {
            return min(A[0], B[0]);
        }
        int amid = min(m, TopK / 2);
        int bmid = TopK - amid;
        if (A[amid - 1] < B[bmid - 1]) {
            return solve(A + amid, m - amid, B, n, TopK - amid);
        }
        if (A[amid - 1] > B[bmid - 1]) {
            return solve(A, m, B + bmid, n - bmid, TopK - bmid);
        }
        return (double)(A[amid - 1]);
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((m + n) % 2) {
            return solve(A, m, B, n, (m + n + 1) / 2);
        } else {
            return 0.5 * (solve(A, m, B, n, (m + n) / 2) + solve(A, m, B, n, (m + n) / 2 + 1));
        }
    }
};