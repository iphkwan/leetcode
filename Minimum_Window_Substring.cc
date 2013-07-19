class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int cnt_map[256], ex_map[256];
        memset(cnt_map, 0, sizeof(cnt_map));
        memset(ex_map, 0, sizeof(ex_map));
        int slen = S.length();
        int tlen = T.length();
        if (slen < tlen || slen == 0 || tlen == 0) {
            return "";
        }
        for (int i = 0; i < tlen; i++) {
            cnt_map[ T[i] ]++;
        }
        int match_count = 0, left = 0, right = 0;
        int st_pos, len = slen + 1;
        while (right < slen) {
            while (right < slen && match_count < tlen) {
                ex_map[ S[right] ]++;
                if (ex_map[ S[right] ] <= cnt_map[ S[right] ]) {
                    match_count++;
                }
                right++;
            }
            while (left < right && ex_map[ S[left] ] > cnt_map[ S[left] ]) {
                ex_map[ S[left] ]--;
                left++;
            }
            if (match_count == tlen) {
                if (len > right - left) {
                    st_pos = left;
                    len = right - left;
                }
            }
            ex_map[ S[left] ]--;
            match_count--;
            left++;
        }
        if (len == slen + 1) {
            return "";
        } else {
            return S.substr(st_pos, len);
        }
    }
};