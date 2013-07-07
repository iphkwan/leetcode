class Solution {
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0, right = n - 1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (A[mid] == target) {
                return true;
            }
            if (A[mid] < A[right]) {
                if (A[mid] < target && target <= A[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else if (A[mid] > A[right]) {
                if (A[left] <= target && target < A[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                right--;
            }
        }
        return false;
    }
};