class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (dividend == 0 || divisor == 0) {
            return 0;
        }
        bool flag = true;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
            flag = false;
        }
        long long diva = dividend;
        long long divb = divisor;
        if (diva < 0) {
            diva = 0 - diva;
        }
        if (divb < 0) {
            divb = 0 - divb;
        }
        long long tmp, count, ret = 0;
        while (diva >= divb) {
            tmp = divb;
            count = 1;
            while (tmp + tmp <= diva) {
                tmp += tmp;
                count += count;
            }
            ret += count;
            diva -= tmp;
        }
        return (int)(flag ? ret : 0 - ret);
    }
};