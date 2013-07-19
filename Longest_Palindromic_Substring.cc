class Solution {
public:
    string init(string s) {
        string ret = "^";
        for (int i = 0; i < s.length(); i++) {
            ret += "#";
            ret += s[i];
        }
        ret += "#$";
        return ret;
    }
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //manacher algorithm
        if (s.length() == 0) {
            return "";
        }
        string t = init(s);
        int tlen = t.length();
        int *p = new int[tlen];
        int id = 0, rightMost = 0;
        for (int i = 1; i < tlen - 1; i++) {
            if (rightMost > i) {
                p[i] = min(rightMost - i, p[2 * id - i]);
            } else {
                p[i] = 0;
            }
            while (t[ i + p[i] + 1 ] == t[i - p[i] - 1]) {
                p[i]++;
            }
            if (i + p[i] > rightMost) {
                rightMost = i + p[i];
                id = i;
            }
        }
        int maxLen = 0;
        for (int i = 1; i < tlen - 1; i++) {
            if (maxLen < p[i]) {
                maxLen = p[i];
                id = i;
            }
        }
        delete []p;
        return s.substr((id - maxLen - 1) / 2, maxLen);
    }
};