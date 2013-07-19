class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int cur = 0;
        long long ret = 0;
        bool flag = true;
        bool numBegin = false;
        while (str[cur] != '\0') {
            if (str[cur] >= '0' && str[cur] <= '9') {
                ret = ret * 10 + (str[cur] - '0');
                if (ret > INT_MAX) {
                    ret = -1;
                    break;
                }
                numBegin = true;
            } else if (str[cur] == '-' && !numBegin) {
                flag = false;
                numBegin = true;
            } else if (str[cur] == '+' && !numBegin) {
                numBegin = true;
            } else if (numBegin || str[cur] != ' '){
                break;
            }
            cur++;
        }
        if (flag) {
            return (ret < 0 ? INT_MAX : ret);
        } else {
            return (ret < 0 ? INT_MIN : 0 - ret);
        }
    }
};