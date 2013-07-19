class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string cur = "1";
        if (n <= 1) {
            return cur;
        }
        string nxt;
        int count;
        for (int i = 2; i <= n; i++) {
            nxt = "";
            count = 0;
            for (int i = 0; i < cur.length(); i++) {
                count = 1;
                while (i + 1 < cur.length() && cur[i] == cur[i + 1]) {
                    count++;
                    i++;
                }
                nxt.append(1, (char)(count + '0'));
                nxt.append(1, cur[i]);
            }
            cur = nxt;
        }
        return cur;
    }
};