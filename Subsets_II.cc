class Solution {
public:
    void dfs(vector<int> &S, vector<vector<int> > &ans, vector<int> &tmp, vector<bool> &vis, int cnt, int total) {
        if (cnt == total) {
            ans.push_back(tmp);
            return;
        }
        dfs(S, ans, tmp, vis, cnt + 1, total);
        if (cnt == 0 || S[cnt] != S[cnt - 1] || vis[cnt - 1] == true) {
            vis[cnt] = true;
            tmp.push_back(S[cnt]);
            dfs(S, ans, tmp, vis, cnt + 1, total);
            tmp.pop_back();
            vis[cnt] = false;
        }
        return;
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        vector<int> tmp;
        vector<bool> vis;
        for (int i = 0; i < S.size(); i++) {
            vis.push_back(false);
        }
        sort(S.begin(), S.end());
        dfs(S, ans, tmp, vis, 0, S.size());
        return ans;
    }
};