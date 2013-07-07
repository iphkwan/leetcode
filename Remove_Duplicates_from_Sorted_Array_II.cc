class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) {
            return 0;
        }
        int cur_num = A[0], cur_count = 1, ans = 0, pos = 0;
        for (int i = 1; i < n; i++) {
            while (i < n && A[i] == cur_num) {
                i++;
                cur_count++;
            }
            cur_count = min(cur_count, 2);
            ans += cur_count;
            while (cur_count--) {
                A[pos++] = cur_num;
            }
            if (i < n) {
                cur_num = A[i];
                cur_count = 1;
            } else {
                cur_count = 0;
            }
        }
        cur_count = min(cur_count, 2);
        ans += cur_count;
        while (cur_count--) {
            A[pos++] = cur_num;
        }
        return ans;
    }
};