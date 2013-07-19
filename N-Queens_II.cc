class Solution {
public:
    void dfs(int row, int leftCross, int rightCross, int &sum) {
        if (row == upperlim) {
            sum++;
            return;
        }
        int cur = (upperlim & (~(row | leftCross | rightCross)));
        int pos;
        while (cur) {
            pos = (cur & (-cur));
            cur -= pos;
            dfs(row + pos, (leftCross + pos) << 1, (rightCross + pos) >> 1, sum);
        }
    }
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        upperlim = (1 << n) - 1;
        int sum = 0;
        dfs(0, 0, 0, sum);
        return sum;
    }
private:
    int upperlim;
};