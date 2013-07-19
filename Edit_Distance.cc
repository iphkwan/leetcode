class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = word1.length();
        int len2 = word2.length();
        if (len1 == 0 || len2 == 0) {
            return len1 + len2;
        }
        vector<vector<int> > dp;
        vector<int> tmp;
        for (int i = 0; i <= len2; i++) {
            tmp.push_back(0);
        }
        for (int i = 0; i <= len1; i++) {
            dp.push_back(tmp);
            dp[i][0] = i;
        }
        for (int i = 1; i <= len2; i++) {
            dp[0][i] = i;
        }
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                dp[i + 1][j + 1] = dp[i][j] + (word1[i] == word2[j] ? 0 : 1);
                if (dp[i + 1][j + 1] > dp[i][j + 1] + 1) {
                    dp[i + 1][j + 1] = dp[i][j + 1] + 1;
                }
                if (dp[i + 1][j + 1] > dp[i + 1][j] + 1) {
                    dp[i + 1][j + 1] = dp[i + 1][j] + 1;
                }
            }
        }
        return dp[len1][len2];
    }
};