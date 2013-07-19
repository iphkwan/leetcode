class Solution {
public:
    void dfs(vector<vector<int> > &ret, vector<int> &tmp, vector<int> &num, int pos, int curSum, int target) {
        if (pos == num.size()) {
            if (curSum == target) {
                ret.push_back(tmp);
            }
            return;
        }
        dfs(ret, tmp, num, pos + 1, curSum, target);
        if (curSum + num[pos] <= target) {
            if (pos > 0 && num[pos] == num[pos - 1] && vis[pos - 1] == false) {
                return;
            }
            tmp.push_back(num[pos]);
            vis[pos] = true;
            dfs(ret, tmp, num, pos + 1, curSum + num[pos], target);
            vis[pos] = false;
            tmp.pop_back();
        }
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        vector<int> tmp;
        if (num.size() == 0) {
            return ret;
        }
        vis = new bool[num.size()];
        memset(vis, false, sizeof(vis));
        sort(num.begin(), num.end());
        dfs(ret, tmp, num, 0, 0, target);
        return ret;
    }
private:
    bool *vis;
};