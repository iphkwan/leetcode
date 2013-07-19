class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ans = "";
        int pa = a.length() - 1;
        int pb = b.length() - 1;
        int nxt = 0, cur;
        while (pa >= 0 && pb >= 0) {
            cur = a[pa] + b[pb] + nxt - '0' - '0';
            if (cur >= 2) {
                cur -= 2;
                nxt = 1;
            } else {
                nxt = 0;
            }
            ans = char(cur + '0') + ans;
            pa--, pb--;
        }
        while (pa >= 0) {
            cur = a[pa] + nxt - '0';
            if (cur >= 2) {
                cur -= 2;
                nxt = 1;
            } else {
                nxt = 0;
            }
            ans = char(cur + '0') + ans;
            pa--;
        }
        while (pb >= 0) {
            cur = b[pb] + nxt - '0';
            if (cur >= 2) {
                cur -= 2;
                nxt = 1;
            } else {
                nxt = 0;
            }
            ans = char(cur + '0') + ans;
            pb--;
        }
        if (nxt) {
            ans = '1' + ans;
        }
        return ans;
    }
};