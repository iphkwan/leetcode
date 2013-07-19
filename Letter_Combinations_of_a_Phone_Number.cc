class Solution {
public:
    void dfs(vector<string> &ret, string &digits, string &tmp, int cur, int target) {
        if (cur == target) {
            ret.push_back(tmp);
            return;
        }
        int num = digits[cur] - '0';
        for (int i = 0; i < mp[num].length(); i++) {
            tmp.append(1, mp[num][i]);
            dfs(ret, digits, tmp, cur + 1, target);
            tmp.resize(tmp.size() - 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        string tmp;
        dfs(ret, digits, tmp, 0, digits.length());
        return ret;
    }
private:
    string mp[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};