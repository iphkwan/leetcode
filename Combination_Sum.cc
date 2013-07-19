class Solution {
public:
    void dfs(vector<vector<int> > &ret, vector<int> &tmp, vector<int> &candidates, int pos, int curSum, int target) {
        if (pos == candidates.size()) {
            if (curSum == target) {
                ret.push_back(tmp);
            }
            return;
        }
        dfs(ret, tmp, candidates, pos + 1, curSum, target);
        if (candidates[pos] + curSum <= target) {
            tmp.push_back(candidates[pos]);
            dfs(ret, tmp, candidates, pos, curSum + candidates[pos], target);
            tmp.pop_back();
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        dfs(ret, tmp, candidates, 0, 0, target);
        return ret;
    }
};