class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<char, int> mp;
        mp['I'] = 1, mp['V'] = 5;
        mp['X'] = 10, mp['L'] = 50;
        mp['C'] = 100, mp['D'] = 500;
        mp['M'] = 1000;
        int ret = mp[ s[s.length() - 1] ];
        for (int i = 0; i < s.length() - 1; i++) {
            if (mp[ s[i] ] < mp[ s[i + 1] ]) {
                ret -= mp[ s[i] ];
            } else {
                ret += mp[ s[i] ];
            }
        }
        return ret;
    }
};