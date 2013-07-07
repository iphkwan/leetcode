class Solution {
public:
    int judge(string &s1, string &s2, vector<vector<vector<int>>> &dp, int pos1, int pos2, int len) {
        if (dp[pos1][pos2][len] != -1) {
            return dp[pos1][pos2][len];
        }
        if (len == 0 || (len == 1 && s1[pos1] == s2[pos2])) {
            return dp[pos1][pos2][len] = 1;
        }
        for (int i = 1; i < len; i++) {
            if (judge(s1, s2, dp, pos1 + i, pos2 + i, len - i) && judge(s1, s2, dp, pos1, pos2, i)) {
                return dp[pos1][pos2][len] = 1;
            }
            if (judge(s1, s2, dp, pos1, pos2 + len - i, i) && judge(s1, s2, dp, pos1 + i, pos2, len - i)) {
                return dp[pos1][pos2][len] = 1;
            }
        }
        return dp[pos1][pos2][len] = 0;
    }
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s1.length() != s2.length()) {
            return false;
        }
        if (s1.length() == 0) {
            return true;
        }
        vector<vector<vector<int>>> dp;
        vector<vector<int>> tmp1;
        vector<int> tmp2;
        for (int i = 0; i <= s1.length(); i++) {
            tmp2.push_back(-1);
        }
        for (int i = 0; i <= s1.length(); i++) {
            tmp1.push_back(tmp2);
        }
        for (int i = 0; i <= s1.length(); i++) {
            dp.push_back(tmp1);
        }
        return judge(s1, s2, dp, 0, 0, s1.length());
    }
};