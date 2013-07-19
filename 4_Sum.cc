class Solution {
public:
    void add(vector<vector<int> > &ret, int a, int b, int c, int d) {
        vector<int> tmp;
        tmp.push_back(a);
        tmp.push_back(b);
        tmp.push_back(c);
        tmp.push_back(d);
        ret.push_back(tmp);
    }
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if (num.size() < 4) {
            return ret;
        }
        sort(num.begin(), num.end());
        int left, right;
        for (int i = 0; i < num.size() - 3; i++) {
            if (i > 0 && num[i] == num[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < num.size() - 2; j++) {
                if (j != i + 1 && num[j] == num[j - 1]) {
                    continue;
                }
                left = j + 1;
                right = num.size() - 1;
                while (left < right) {
                    if (left != j + 1 && num[left] == num[left - 1]) {
                        left++;
                        continue;
                    }
                    if (right != num.size() - 1 && num[right] == num[right + 1]) {
                        right--;
                        continue;
                    }
                    int tmp = num[i] + num[j] + num[left] + num[right];
                    if (tmp == target) {
                        add(ret, num[i], num[j], num[left], num[right]);
                        left++;
                    } else if (tmp < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return ret;
    }
};