class Solution {
public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ret = 0;
        if (ratings.size() == 0)
            return ret;
        vector<int> dp(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++)
            if (ratings[i] > ratings[i - 1])
                dp[i] = dp[i - 1] + 1;

        ret = dp[ratings.size() - 1];
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                dp[i] = max(dp[i], dp[i + 1] + 1);
            }
            ret += dp[i];
        }
        return ret;
    }
};
