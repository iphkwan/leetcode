class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans;
        int row = matrix.size();
        if (row == 0) {
            return ans;
        }
        int col = matrix[0].size();
        int ux = 0, uy = 0, dx = row - 1, dy = col - 1;
        while (ux < dx && uy < dy) {
            for (int i = uy; i < dy; i++) {
                ans.push_back(matrix[ux][i]);
            }
            for (int i = ux; i < dx; i++) {
                ans.push_back(matrix[i][dy]);
            }
            for (int i = dy; i > uy; i--) {
                ans.push_back(matrix[dx][i]);
            }
            for (int i = dx; i > ux; i--) {
                ans.push_back(matrix[i][uy]);
            }
            ux++, uy++;
            dx--, dy--;
        }
        if (ux == dx) {
            for (int i = uy; i <= dy; i++) {
                ans.push_back(matrix[ux][i]);
            }
        } else if (uy == dy) {
            for (int i = ux; i <= dx; i++) {
                ans.push_back(matrix[i][uy]);
            }
        }
        return ans;
    }
};