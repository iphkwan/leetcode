class Solution {
public:
    void dfs(vector<vector<string> > &ans, vector<string> &tmp, int row, int leftCross, int rightCross) {
        if (row == upperlimit) {
            ans.push_back(tmp);
            return;
        }
        int cur = upperlimit & (~(row | leftCross | rightCross));
        int nxt, pos;
        string str;
        while (cur) {
            nxt = (cur & (-cur));
            cur -= nxt;
            pos = nxt + upperlimit + 1;;
            str = "";
            while (pos > 1) {
                str += ((pos & 1) ? 'Q': '.');
                pos >>= 1;
            }
            tmp.push_back(str);
            dfs(ans, tmp, row + nxt, (leftCross + nxt) << 1, (rightCross + nxt) >> 1);
            tmp.pop_back();
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > ans;
        vector<string> tmp;
        upperlimit = (1 << n) - 1;
        dfs(ans, tmp, 0, 0, 0);
        return ans;
    }
private:
    int upperlimit;
};