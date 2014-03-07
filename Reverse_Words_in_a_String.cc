//O(1) space solution
// First, normalize the string, then reverse substring and at last reverse the whole string.
class Solution {
public:
    void reverseWords(string &s) {
        preHandle(s);
        int left = 0, right;
        for (right = 0; right < s.length(); right++) {
            if (s[right] != ' ')
                continue;
            if (left < right - 1)
                reverse(s, left, right - 1);
            left = right + 1;
        }
        if (left < right - 1)
            reverse(s, left, right - 1);
        reverse(s, 0, right - 1);
        return;
    }
private:
    void preHandle(string &s) {
        int slow = 0, fast = 0;
        while (slow < s.length()) {
            while (fast < s.length() && s[fast] == ' ')
                fast++;
            if (fast == s.length())
                break;
            if (slow != 0 && fast > 0 && s[fast - 1] == ' ')
                s[slow++] = ' ';
            s[slow++] = s[fast++];
        }
        s.resize(slow);
    }
    void reverse(string &s, int st, int ed) {
        char ch;
        while (st < ed) {
            ch = s[st];
            s[st] = s[ed];
            s[ed] = ch;
            st++, ed--;
        }
    }
};
