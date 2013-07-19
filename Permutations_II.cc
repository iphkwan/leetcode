class Solution {
public:
    void dfs(vector<vector<int> > &ans, vector<int> &tmp, vector<int> &num, vector<bool> &vis, int cur) {
        if (cur == num.size()) {
            ans.push_back(tmp);
            return;
        }
        for (int i = 0; i < num.size(); i++) {
            if (vis[i] == true) {
                continue;
            }
            if (i != 0 && num[i] == num[i - 1] && vis[i - 1] == false) {
                continue;
            }
            vis[i] = true;
            tmp.push_back(num[i]);
            dfs(ans, tmp, num, vis, cur + 1);
            tmp.pop_back();
            vis[i] = false;
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        vector<int> tmp;
        if (num.size() == 0) {
            return ans;
        }
        sort(num.begin(), num.end());
        vector<bool> vis;
        for (int i = 0; i < num.size(); i++) {
            vis.push_back(false);
        }
        dfs(ans, tmp, num, vis, 0);
        return ans;
    }
};