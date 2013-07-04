class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if (len1 + len2 != len3) {
            return false;
        }
        vector<vector<bool> > dp;
        vector<bool> tmp;
        for (int i = 0; i <=len2; i++) {
            tmp.push_back(false);
        }
        for (int i = 0; i <= len1; i++) {
            dp.push_back(tmp);
        }
        dp[0][0] = true;
        for (int i = 1; i <= len1; i++) {
            if (s1[i - 1] == s3[i - 1]) {
                dp[i][0] = true;
            } else {
                break;
            }
        }
        for (int i = 1; i <= len2; i++) {
            if (s2[i - 1] == s3[i - 1]) {
                dp[0][i] = true;
            } else {
                break;
            }
        }
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (s1[i - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] | dp[i - 1][j];
                }
                if (s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] | dp[i][j - 1];
                }
            }
        }
        return dp[len1][len2];
    }
};