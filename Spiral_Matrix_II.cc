class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0, right = n - 1, cur = 1;
        vector<vector<int> > ans;
        vector<int> tmp;
        for (int i = 0; i < n; i++) {
            tmp.push_back(0);
        }
        for (int i = 0; i < n; i++) {
            ans.push_back(tmp);
        }
        while (left <= right) {
            if (left == right) {
                ans[left][left] = cur;
                break;
            }
            for (int i = left; i < right; i++) {
                ans[left][i] = cur;
                ans[i][right] = cur + (right - left);
                ans[n - 1 - left][n - 1 - i] = cur + 2 * (right - left);
                ans[n - 1 - i][left] = cur + 3 * (right - left);
                cur++;
            }
            cur += (3 * (right - left));
            left++;
            right--;
        }
        return ans;
    }
};