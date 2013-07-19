class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (m == 0 || n == 0) {
            return 0;
        }
        vector<vector<int> > dp;
        vector<int> tmp;
        for (int i = 0; i <= n; i++) {
            tmp.push_back(0);
        }
        for (int i = 0; i <= m; i++) {
            dp.push_back(tmp);
        }
        dp[0][1] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};