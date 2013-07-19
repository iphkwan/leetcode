class Solution {
public:
    bool dfs(vector<vector<char> > &board, int cur) {
        if (cur == count) {
            return true;
        }
        int r = pos[cur] / 9;
        int c = pos[cur] % 9;
        int s = (r / 3) * 3 + (c / 3);
        for (int i = 1; i <= 9; i++) {
            if (rUsed[r][i] || cUsed[c][i] || sUsed[s][i]) {
                continue;
            }
            rUsed[r][i] = cUsed[c][i] = sUsed[s][i] = true;
            board[r][c] = (char)(i + '0');
            if (dfs(board, cur + 1) == true) {
                return true;
            }
            board[r][c] = '.';
            rUsed[r][i] = cUsed[c][i] = sUsed[s][i] = false;
        }
        return false;
    }
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        memset(rUsed, false, sizeof(rUsed));
        memset(cUsed, false, sizeof(cUsed));
        memset(sUsed, false, sizeof(sUsed));
        count = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (rUsed[i][ board[i][j] - '0' ] || cUsed[j][ board[i][j] - '0' ] || sUsed[(i / 3) * 3 + (j / 3)][ board[i][j] - '0' ]) {
                        return false;
                    }
                    rUsed[i][ board[i][j] - '0' ] = true;
                    cUsed[j][ board[i][j] - '0' ] = true;
                    sUsed[(i / 3) * 3 + (j / 3)][ board[i][j] - '0' ] = true;
                } else {
                    pos[count++] = i * 9 + j;
                }
            }
        }
        return true;
        //return dfs(board, 0);
    }
private:
    bool rUsed[9][10], cUsed[9][10], sUsed[9][10];
    int pos[81], count;
};