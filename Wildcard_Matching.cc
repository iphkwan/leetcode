class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
         
        const char* star=NULL;
        const char* ss=s; 
        while (*s) {
            if (*p == '?' || *p == *s) {
                s++;
                p++;
                continue;
            }
            if (*p == '*') {
                star = p++;
                ss = s;
                continue;
            }
            if (star) {
                p = star + 1; 
                s = ++ss;
                continue;      
            }
            return false;
        }
        while (*p == '*') {
            p++;
        }
        return !(*p);
    }
};