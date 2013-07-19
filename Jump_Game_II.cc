class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n <= 1) {
            return 0;
        }
        int cur_pos = 0, max_pos = 0, ret = 0;
        while (cur_pos <= max_pos) {
            ret++;
            int nxt_pos = max_pos + 1;
            for (int i = cur_pos; i < nxt_pos; i++) {
                if (A[i] + i > max_pos) {
                    max_pos = A[i] + i;
                    if (max_pos >= n - 1) {
                        return ret;
                    }
                }
            }
            cur_pos = nxt_pos;
        }
        return -1;
    }
};