class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0, right = strlen(s) - 1;
        while (left <= right && s[left] == ' ') {
            left++;
        }
        while (left <= right && s[right] == ' ') {
            right--;
        }
        if (left > right) {
            return false;
        }
        if (left < right && (s[left] == '+' || s[left] == '-')) {
            left++;
        }
        bool isDot = false;
        bool isExp = false;
        bool isLeft = false, isRight = false;
        for (int i = left; i <= right; i++) {
            if (s[i] == '.') {
                if (isDot || isRight || isExp) {
                    return false;
                }
                isDot = true;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (!isLeft || isExp) {
                    return false;
                }
                isExp = true;
            } else if (s[i] == '+' || s[i] == '-') {
                if (!(s[i - 1] == 'e' || s[i - 1] == 'E')) {
                    return false;
                }
            } else if (s[i] >= '0' && s[i] <= '9') {
                if (isExp) {
                    isRight = true;
                } else {
                    isLeft = true;
                }
            } else {
                return false;
            }
        }
        if (!isLeft || (isExp && !isRight)) {
            return false;
        }
        return true;
    }
};