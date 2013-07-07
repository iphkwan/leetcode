class Solution {
public:
    bool judge(string &s, int st) {
        int num = 0;
        for (int i = 0; i < 3; i++) {
            num = num * 10 + (s[st + i] - '0');
        }
        if (num >= 0 && num <= 255) {
            return true;
        }
        return false;
    }
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ans;
        int len = s.length(), slen;
        if (len < 4 || len > 12) {
            return ans;
        }
        for (int i = 1; i <= 3; i++) {
            if (i >= 2 && s[0] == '0') {
                break;
            }
            if (i == 3 && judge(s, 0) == false) {
                break;
            }
            for (int j = 1; j <=3 && i + j < len; j++) {
                if (j >= 2 && s[i] == '0') {
                    break;
                }
                if (j == 3 && judge(s, i) == false) {
                    break;
                }
                for (int k = 1; k <= 3 && i + j + k < len; k++) {
                    if (k >= 2 && s[i + j] == '0') {
                        break;
                    }
                    if (k == 3 && judge(s, i + j) == false) {
                        break;
                    }
                    slen = len - i - j - k;
                    if (slen > 3 || (slen == 3 && judge(s, i + j + k) == false)) {
                        continue;
                    }
                    if (slen >= 2 && s[i + j + k] == '0') {
                        continue;
                    }
                    string tmp = "";
                    tmp += s.substr(0, i);
                    tmp += '.';
                    tmp += s.substr(i, j);
                    tmp += '.';
                    tmp += s.substr(i + j, k);
                    tmp += '.';
                    tmp += s.substr(i + j + k, slen);
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
};