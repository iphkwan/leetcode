class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int NumOfStrs = strs.size();
        string ret = "";
        if (NumOfStrs == 0) {
            return ret;
        }
        bool flag = true;
        for (int i = 0; i < strs[0].length(); i++) {
            for (int j = 1; j < NumOfStrs; j++) {
                if (i >= strs[j].length() || strs[0][i] != strs[j][i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ret.append(1, strs[0][i]);
            } else {
                break;
            }
        }
        return ret;
    }
};