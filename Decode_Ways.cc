class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len  = s.length();
        if (len == 0 || s[0] == '0') {
            return 0;
        }
        vector<int> dp;
        for (int i = 0; i <= len; i++) {
            dp.push_back(0);
        }
        dp[1] = dp[0] = 1;
        for (int i = 2; i <= len; i++) {
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (num >= 10 && num <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[len];
    }
};