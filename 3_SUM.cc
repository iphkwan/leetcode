class Solution {
public:
    void add(vector<vector<int> > &ret, int a, int b, int c) {
        vector<int> tmp;
        tmp.push_back(a);
        tmp.push_back(b);
        tmp.push_back(c);
        ret.push_back(tmp);
    }
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        if (num.size() < 3) {
            return ans;
        }
        sort(num.begin(), num.end());
        int left, right;
        for (int i = 0; i < num.size() - 2; i++) {
            if (i > 0 && num[i] == num[i - 1]) {
                continue;
            }
            left = i + 1;
            right = num.size() - 1;
            while (left < right) {
                if (left > i + 1 && num[left] == num[left - 1]) {
                    left++;
                    continue;
                }
                if (right < num.size() - 1 && num[right] == num[right + 1]) {
                    right--;
                    continue;
                }
                if (num[left] + num[right] == 0 - num[i]) {
                    add(ans, num[i], num[left], num[right]);
                    left++;
                } else if (num[left] + num[right] > 0 - num[i]) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return ans;
    }
};