class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0, right = x, mid;
        while (left < right) {
            mid = left + (right - left) / 2 + 1;
            if (x / mid == mid) {
                return mid;
            } else if (x / mid < mid) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        return right;
    }
};