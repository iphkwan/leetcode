class Solution {
public:
    vector< vector<int> > vt;
    bool judge(string &s, int i, int j) {
        if (i > j)
            return false;
        if (vt[i][j] != -1)
            return vt[i][j];
        if (i == j)
            return vt[i][j] = 1;
        if (s[i] != s[j])
            return vt[i][j] = 0;
        else {
            if (i + 1 == j)
                return vt[i][j] = 1;
            else
                return vt[i][j] = judge(s, i + 1, j - 1);
        }
    }
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        if (len < 2)
            return 0;
        vector<int> dp, tmp;
        dp.clear(), tmp.clear(), vt.clear();
        for (int i = 0; i < len; i++) {
            dp.push_back(0);
            tmp.push_back(-1);
        }
        for (int i = 0; i < len; i++) {
            vt.push_back(tmp);
        }
        for (int i = 1; i < len; i++) {
            if (judge(s, 0, i)) {
                dp[i] = 0;
                continue;
            }
            int ans = i;
            for (int j = 0; j < i; j++) {
                if (judge(s, j + 1, i))
                    ans = min(ans, dp[j] + 1);
                else
                    ans = min(ans, dp[j] + i - j);
            }
            dp[i] = ans;
        }
        return dp[len - 1];
    }
};