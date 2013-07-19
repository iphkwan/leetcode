class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0) {
            return false;
        }
        int helper = 1;
        while (x / helper >= 10) {
            helper *= 10;
        }
        while (x) {
            if (x / helper != x % 10) {
                return false;
            }
            x = (x % helper) / 10;
            helper /= 100;
        }
        return true;
    }
};