class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> cnt, pre;
        for (int i = 1; i <= rowIndex + 1; i++) {
            if (pre.size() == 0) {
                cnt.push_back(1);
            } else {
                cnt.push_back(1);
                for (int j = 1; j < i - 1; j++)
                    cnt.push_back(pre[j - 1] + pre[j]);
                cnt.push_back(1);
            }
            pre = cnt;
            cnt.clear();
        }
        return pre;
    }
};