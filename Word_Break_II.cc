class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (s == "")
            return vector<string>();
        dp.assign(s.length() + 1, vector<int>());
        dp[0].push_back(-1);
        for (int i = 0; i < s.length(); i++) {
            if (dp[i].size() == 0)
                continue;
            for (int j = 1; i + j <= s.length(); j++) {
                if (dict.find(s.substr(i, j)) != dict.end()) {
                    dp[i + j].push_back(i);
                }
            }
        }
        
        vector<string> ret;
        string tmp = "";
        
        dfs(ret, tmp, s, s.length());
        return ret;
    }
private:
    vector< vector<int> > dp;
    void dfs(vector<string> &ret, string tmp, string &s, int cur) {
        if (cur == 0) {
            ret.push_back(tmp);
            return;
        }
        for (int i = 0; i < dp[cur].size(); i++) {
            if (cur == s.length()) {
                dfs(ret, s.substr(dp[cur][i], cur - dp[cur][i]), s, dp[cur][i]);
            } else {
                dfs(ret, s.substr(dp[cur][i], cur - dp[cur][i]) + " " + tmp, s, dp[cur][i]);
            }
        }
    }
};
