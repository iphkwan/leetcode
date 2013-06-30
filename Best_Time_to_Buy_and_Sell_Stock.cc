class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() == 0)
            return 0;
        int cnt = prices[0];
        int ans = -0x7ffffff;
        for (int i = 0; i < prices.size(); i++) {
            ans = max(ans, prices[i] - cnt);
            cnt = min(cnt, prices[i]);
        }
        return ans;
    }
};