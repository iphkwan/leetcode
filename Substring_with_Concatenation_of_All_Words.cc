class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        int slen = S.length();
        int wordsLen = L.size();
        if (wordsLen == 0) {
            for (int i = 0; i < slen; i++) {
                ret.push_back(i);
            }
            return ret;
        }
        wordsLen *= L[0].length();
        map<string, int> mp;
        map<string, int> cur;
        for (int i = 0; i < L.size(); i++) {
            mp[ L[i] ]++;
        }
        for (int i = 0; i + wordsLen <= slen; i++) {
            cur.clear();
            bool flag = true;
            for (int j = 0; j < L.size(); j++) {
                string tmp = S.substr(i + j * L[0].length(), L[0].length());
                if (mp[tmp] > cur[tmp]) {
                    cur[tmp]++;
                } else {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};