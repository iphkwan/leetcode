class Solution {
public:
    void clockwiseSwap(int &a, int &b, int &c, int &d) {
        int tmp = a;
        a = d;
        d = c;
        c = b;
        b = tmp;
    }
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = matrix.size();
        if (n <= 1) {
            return;
        }
        for (int i = 0; 2 * (i + 1) <= n; i++) {
            for (int j = i; j < n - 1 - i; j++) {
                clockwiseSwap(matrix[i][j], matrix[j][n - 1 - i], matrix[n - 1 - i][n - 1 - j], matrix[n - 1 - j][i]);
            }
        }
        return;
    }
};