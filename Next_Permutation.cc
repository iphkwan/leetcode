class Solution {
public:
    void reverse(vector<int> &num, int st, int ed) {
        while (st < ed) {
            swap(num[st], num[ed]);
            st++, ed--;
        }
    }
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size() <= 1) {
            return;
        }
        int left, right;
        bool flag = false;
        for (left = num.size() - 2; !flag && left >= 0; left--) {
            for (right = num.size() - 1; right > left; right--) {
                if (num[left] < num[right]) {
                    flag = true;
                    swap(num[left], num[right]);
                    break;
                }
            }
        }
        if (flag) {
            reverse(num, left + 2, num.size() - 1);
        } else {
            reverse(num, 0, num.size() - 1);
        }
    }
};