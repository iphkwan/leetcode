class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) {
            return 0;
        }
        int max_sum = A[0];
        int cur_max_sum = A[0];
        for (int i = 1; i < n; i++) {
            cur_max_sum = max(cur_max_sum + A[i], A[i]);
            max_sum = max(max_sum, cur_max_sum);
        }
        return max_sum;
    }
};