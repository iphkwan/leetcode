class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() == 0)
            return 0;
        int cnt = prices[0];
        vector<int> ans1, ans2;
        int ans = 0;
        for (int i = 0; i < prices.size(); i++) {
            ans1.push_back(prices[i] - cnt);
            ans2.push_back(0);
            cnt = min(prices[i], cnt);
        }
        cnt = prices[prices.size() - 1];
        for (int i = prices.size() - 1; i >= 0; i--) {
            ans2[i] = cnt - prices[i];
            cnt = max(cnt, prices[i]);
        }
        for (int i = 1; i < prices.size(); i++) {
            ans1[i] = max(ans1[i], ans1[i - 1]);
            ans2[prices.size() - i - 1] = max(ans2[prices.size() - i - 1], ans2[prices.size() - i]);
        }
        for (int i = 0; i < prices.size(); i++)
            ans = max(ans, ans1[i] + ans2[i]);
        return ans;
    }
};