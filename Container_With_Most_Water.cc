class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (height.size() <= 1) {
            return 0;
        }
        int ret = 0, left = 0, right = height.size() - 1;
        while (left < right) {
            ret = max(ret, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return ret;
    }
};