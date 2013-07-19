class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        string ret = "";
        ret.append(num1.length() + num2.length(), '0');
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int nxt = 0, cur, tmp;
        for (int i = 0; i < num2.length(); i++) {
            for (int j = 0; j < num1.length(); j++) {
                cur = ret[i + j] - '0' + nxt + (num2[i] - '0') * (num1[j] - '0');
                ret[i + j] = (cur % 10) + '0';
                nxt = cur / 10;
            }
            tmp = num1.length();
            while (nxt > 0) {
                cur = ret[i + tmp] - '0' + nxt;
                ret[i + tmp] = (cur % 10) + '0';
                nxt = cur / 10;
                tmp++;
            }
        }
        while (ret.length() > 1 && ret[ret.length() - 1] == '0') {
            ret.resize(ret.length() - 1);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};