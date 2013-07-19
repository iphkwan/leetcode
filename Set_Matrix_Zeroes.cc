class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = matrix.size();
        if (row == 0) {
            return;
        }
        int col = matrix[0].size();
        bool col_flag = false, row_flag = false;
        for (int i = 0; i < col; i++) {
            if (matrix[0][i] == 0) {
                col_flag = true;
                break;
            }
        }
        for (int i = 0; i < row; i++) {
            if (matrix[i][0] == 0) {
                row_flag = true;
                break;
            }
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < row; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < col; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < col; i++) {
            if (matrix[0][i] == 0) {
                for (int j = 1; j < row; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
        if (col_flag) {
            for (int i = 0; i < col; i++) {
                matrix[0][i] = 0;
            }
        }
        if (row_flag) {
            for (int i = 0; i < row; i++) {
                matrix[i][0] = 0;
            }
        }
        return;
    }
};