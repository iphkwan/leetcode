class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = triangle.size();
        if (n <= 0)
            return 0;
        vector<vector<int>> dp;
        vector<int> tmp;
        for (int i = 0; i <= n + 1; i++)
            tmp.push_back(0);
        dp.push_back(tmp);
        dp.push_back(tmp);
        int f = 0;
        for (int i = 0; i < n; i++) {
            f = 1 - f;
            dp[f][1] = triangle[i][0] + dp[1 - f][1];
            dp[f][i + 1] = triangle[i][i] + dp[1 - f][i];
            for (int j = 1; j < i; j++)
                dp[f][j + 1] = triangle[i][j] + min(dp[1 - f][j], dp[1 - f][j + 1]);
        }
        int ans = dp[f][1];
        for (int i = 2; i <= n; i++)
            ans = min(ans, dp[f][i]);
        return ans;
    }
};