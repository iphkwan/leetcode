class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = obstacleGrid.size();
        if (row == 0) {
            return 0;
        }
        int col = obstacleGrid[0].size();
        vector<vector<int> > dp;
        vector<int> tmp;
        for (int i = 0; i < col; i++) {
            tmp.push_back(0);
        }
        for (int i = 0; i < row; i++) {
            dp.push_back(tmp);
        }
        dp[0][0] = (obstacleGrid[0][0] == 1) ? 0 : 1;
        for (int i = 1; i < row; i++) {
            dp[i][0] = (obstacleGrid[i][0] == 1) ? 0 : dp[i - 1][0];
        }
        for (int i = 1; i < col; i++) {
            dp[0][i] = (obstacleGrid[0][i] == 1) ? 0 : dp[0][i - 1];
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[row - 1][col - 1];
    }
};