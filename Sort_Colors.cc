class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0, right = n - 1, cur = 0;
        while (cur <= right) {
            if (A[cur] == 0) {
                A[cur] = A[left] ;
                A[left++] = 0;
                if (left > cur) {
                    cur++;
                }
            } else if (A[cur] == 2) {
                A[cur] = A[right];
                A[right--] = 2;
            } else {
                cur++;
            }
        }
    }
};