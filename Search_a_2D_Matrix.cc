class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = matrix.size();
        if (row == 0) {
            return false;
        }
        int col = matrix[0].size();
        
        //find row num
        int left = 0, right = row - 1, mid;
        while (left < right) {
            mid = left + (right - left) / 2 + 1;
            if (matrix[mid][0] == target) {
                return true;
            } else if (matrix[mid][0] > target) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }
        int tar_row = right;
        
        //find col num
        left = 0;
        right = col - 1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (matrix[tar_row][mid] == target) {
                return true;
            } else if (matrix[tar_row][mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};