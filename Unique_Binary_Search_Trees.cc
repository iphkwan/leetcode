class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> dp;
        for (int i = 0; i <= n; i++) {
            dp.push_back(0);
        }
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += (dp[j - 1] * dp[i - j]);
            }
        }
        return dp[n];
    }
};