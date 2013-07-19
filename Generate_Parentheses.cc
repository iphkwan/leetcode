class Solution {
public:
    void dfs(vector<string> &ret, string &tmp, int left, int right, int n) {
        if (left == n && right == n) {
            ret.push_back(tmp);
        }
        if (left < n) {
            tmp.append(1, '(');
            dfs(ret, tmp, left + 1, right, n);
            tmp.resize(tmp.size() - 1);
        }
        if (left > right) {
            tmp.append(1, ')');
            dfs(ret, tmp, left, right + 1, n);
            tmp.resize(tmp.size() - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        string tmp = "";
        dfs(ret, tmp, 0, 0, n);
        return ret;
    }
};