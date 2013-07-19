class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        string symbol = "IVXLCDM", ret = "";
        int div = 1000;
        for (int i = 6; i >= 0; i -= 2) {
            int tmp = num / div;
            if (tmp == 0) {
                div /= 10;
                continue;
            }
            if (tmp <= 3) {
                ret.append(tmp, symbol[i]);
            } else if (tmp == 4) {
                ret.append(1, symbol[i]);
                ret.append(1, symbol[i + 1]);
            } else if (tmp == 5) {
                ret.append(1, symbol[i + 1]);
            } else if (tmp <= 8) {
                ret.append(1, symbol[i + 1]);
                ret.append(tmp - 5, symbol[i]);
            } else {
                ret.append(1, symbol[i]);
                ret.append(1, symbol[i + 2]);
            }
            num = num % div;
            div = div / 10;
        }
        return ret;
    }
};