class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int slen = S.length();
        int tlen = T.length();
        if (slen == 0 || tlen == 0)
            return 0;
        vector<vector<int>> dp;
        vector<int> tmp;
        for (int i = 0; i < tlen; i++)
            tmp.push_back(0);
        for (int i = 0; i < slen; i++)
            dp.push_back(tmp);
        for (int i = 0; i < slen; i++)
            for (int j = 0; j <= i && j < tlen; j++) {
                if (S[i] == T[j]) {
                    dp[i][j] = (i == 0 || j == 0) ? 1 : dp[i - 1][j - 1];
                }
                if (i > j)
                    dp[i][j] += dp[i - 1][j];
            }
        return dp[slen - 1][tlen - 1];
    }
};