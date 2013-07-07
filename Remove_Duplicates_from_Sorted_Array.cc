class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) {
            return 0;
        }
        int pos = 0;
        for (int i = 1; i < n; i++) {
            if (A[i] != A[pos]) {
                A[++pos] = A[i];
            }
        }
        return pos + 1;
    }
};