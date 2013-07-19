class Solution {
public:
    int abs(int x, int y) {
        if (x >= y) {
            return x - y;
        } else {
            return y - x;
        }
    }
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size() < 3) {
            return 0;
        }
        sort(num.begin(), num.end());
        int ret = num[0] + num[1] + num[2];
        int left, right, tmp;
        for (int i = 0; i < num.size() - 2; i++) {
            left = i + 1;
            right = num.size() - 1;
            while (left < right) {
                tmp = num[i] + num[left] + num[right];
                if (abs(target, tmp) < abs(target, ret)) {
                    ret = tmp;
                    if (ret == target) {
                        return ret;
                    }
                }
                if (tmp < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return ret;
    }
};