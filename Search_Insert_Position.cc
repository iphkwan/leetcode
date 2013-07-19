class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0, right = n - 1, mid;
        while (left < right) {
            mid = left + (right - left + 1) / 2;
            if (A[mid] > target) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        return (A[left] >= target ? left : left + 1);
    }
};