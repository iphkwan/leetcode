class Solution {
public:
    bool isalphanumeric(char &ch) {
        if (ch >= '0' && ch <= '9')
            return true;
        if (ch >= 'A' && ch <= 'Z') {
            ch += 32;
            return true;
        }
        if (ch >= 'a' && ch <= 'z')
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0, r = s.length() - 1;
        while (l <= r) {
            while (l < s.length() && !isalphanumeric(s[l]))
                l++;
            while (r >= 0 && !isalphanumeric(s[r]))
                r--;
            if (l <= r && s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};