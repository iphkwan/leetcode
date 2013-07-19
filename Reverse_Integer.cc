class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret = 0;
        while (x) {
            ret = ret * 10 + (x % 10);
            x /= 10;
        }
        return ret;
    }
};