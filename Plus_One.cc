class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        int nxt = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i] += nxt;
            if (digits[i] == 10) {
                digits[i] = 0;
                nxt = 1;
            } else {
                nxt = 0;
                break;
            }
        }
        if (nxt) {
            ret.push_back(1);
        }
        for (int i = 0; i < digits.size(); i++) {
            ret.push_back(digits[i]);
        }
        return ret;
    }
};