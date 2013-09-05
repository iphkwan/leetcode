class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.size() == 0) {
            return 0;
        }
        vector<vector<int> > dp;
        vector<int> tmp;
        for (int i = 0; i < matrix[0].size(); i++) {
            tmp.push_back(0);
        }
        for (int i = 0; i < matrix.size(); i++) {
            dp.push_back(tmp);
            if (matrix[i][0] == '1') {
                dp[i][0] = 1;
            }
            for (int j = 1; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = dp[i][j - 1] + 1;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                int width = matrix[i].size();
                for (int k = i; k >= 0; k--) {
                    if (dp[k][j] == 0) {
                        break;
                    }
                    width = min(width, dp[k][j]);
                    ans = max(ans, width * (i - k + 1));
                }
            }
        }
        return ans;
    }
};


//O(n^2) time solution
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret = 0;
        int row = matrix.size();
        if (row == 0)   return ret;
        int col = matrix[0].size();
        vector<int> dp(col, 0);
        stack<int> st;
        int tmp;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                dp[j] = (matrix[i][j] == '1') ? (dp[j] + 1) : 0;
                while (!st.empty() && dp[j] < dp[ st.top() ]) {
                    tmp = st.top();
                    st.pop();
                    ret = max(ret, dp[tmp] * ((st.empty() ? j : (j - 1 - st.top()))));
                }
                st.push(j);
            }
            while (!st.empty()) {
                tmp = st.top();
                st.pop();
                ret = max(ret, dp[tmp] * ((st.empty() ? col : (col - 1 - st.top()))));
            }
        }
        return ret;
    }
};

