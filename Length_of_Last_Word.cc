class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = 0, cur = 0;
        while (s[cur] != '\0') {
            if (s[cur] != ' ') {
                len = 0;
                while (s[cur] != '\0' && s[cur] != ' ') {
                    len++;
                    cur++;
                }
            } else {
                cur++;
            }
        }
        return len;
    }
};