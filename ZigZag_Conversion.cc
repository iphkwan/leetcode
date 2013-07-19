class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (nRows <= 1) {
            return s;
        }
        string ret = "";
        int gaps = 2 * nRows - 2;
        for (int i = 0; i < nRows; i++) {
            for (int j = i; j < s.length(); j += gaps) {
                ret += s[j];
                if (i != 0 && i != nRows - 1 && j + gaps - 2 * i < s.length()) {
                    ret += s[j + gaps - 2 * i];
                }
            }
        }
        return ret;
    }
};