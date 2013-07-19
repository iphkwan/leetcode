class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = n - 1; i >= 0; i--) {
            if (A[i] == elem) {
                A[i] = A[n - 1];
                n--;
            }
        }
        return n;
    }
};