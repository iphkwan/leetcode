class Solution {
public:
    bool judge(int x, int y) {
        return (x >= 0 && x < row && y >= 0 && y < col);
    }
    bool dfs(vector<vector<char> > &board, string &word, int cnt, int x, int y) {
        if (cnt == word.length()) {
            return true;
        }
        int tx, ty;
        for (int i = 0; i < 4; i++) {
            tx = x + dx[i];
            ty = y + dy[i];
            if (judge(tx, ty) && board[tx][ty] == word[cnt]) {
                board[tx][ty] = '#';
                if (dfs(board, word, cnt + 1, tx, ty)) {
                    board[tx][ty] = word[cnt];
                    return true;
                }
                board[tx][ty] = word[cnt];
            }
        }
        return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (word.length() == 0) {
            return true;
        }
        row = board.size();
        if (row == 0) {
            return false;
        }
        col = board[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == word[0]) {
                    board[i][j] = '#';
                    if (dfs(board, word, 1, i, j)) {
                        return true;
                    }
                    board[i][j] = word[0];
                }
            }
        }
        return false;
    }
private:
    int row, col;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
};