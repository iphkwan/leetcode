class Solution {
public:
    void init(int *p, char *needle, int len) {
        p[0] = -1;
        int j = -1;
        for (int i = 1; i < len; i++) {
            while (j > -1 && needle[i] != needle[j + 1]) {
                j = p[j];
            }
            if (needle[j + 1] == needle[i]) {
                j++;
            }
            p[i] = j;
        }
    }
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = strlen(needle);
        if (len == 0) {
            return haystack;
        }
        int *p = new int[len];
        init(p, needle, len);
        int i = 0, j = -1;
        while (haystack[i] != '\0') {
            while (j > -1 && haystack[i] != needle[j + 1]) {
                j = p[j];
            }
            if (haystack[i] == needle[j + 1]) {
                j++;
            }
            if (j == len - 1) {
                delete []p;
                return haystack + i - len + 1;
            }
            i++;
        }
        delete []p;
        return NULL;
    }
};