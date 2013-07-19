class Solution {
public:
    void dfs(vector<vector<int> > &ans, vector<int> &tmp, int cnt, int n, int k) {
        if (tmp.size() == k) {
            ans.push_back(tmp);
            return;
        }
        if (cnt > n) {
            return;
        }
        dfs(ans, tmp, cnt + 1, n, k);
        tmp.push_back(cnt);
        dfs(ans, tmp, cnt + 1, n, k);
        tmp.pop_back();
    }
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        vector<int> tmp;
        dfs(ans, tmp, 1, n, k);
        return ans;
    }
};