class Solution {
public:
    void dfs(vector<vector<int> > &ans, vector<int> &tmp, vector<int> &S, int cnt, int total) {
        if (cnt == total) {
            ans.push_back(tmp);
            return;
        }
        dfs(ans, tmp, S, cnt + 1, total);
        tmp.push_back(S[cnt]);
        dfs(ans, tmp, S, cnt + 1, total);
        tmp.pop_back();
        return;
    }
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        vector<int> tmp;
        sort(S.begin(), S.end());
        dfs(ans, tmp, S, 0, S.size());
        return ans;
    }
};