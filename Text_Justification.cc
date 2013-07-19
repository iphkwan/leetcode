class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ans;
        string tmp;
        int word_len = 0, blank_len, gaps;
        for (int i = 0; i < words.size(); i++) {
            int j = i + 1;
            tmp = words[i];
            word_len = words[i].length();
            blank_len = 0;
            while (j < words.size() && word_len + blank_len + words[j].length() < L) {
                word_len += words[j].length();
                blank_len++;
                j++;
            }
            blank_len = L - word_len;
            if (j == i + 1) {
                while (blank_len--) {
                    tmp += ' ';
                }
            } else if (j < words.size()){
                for (int k = i + 1; k < j; k++) {
                    gaps = ((blank_len % (j - k)) ? 1 : 0);
                    gaps += (blank_len / (j - k));
                    blank_len -= gaps;
                    while (gaps--) {
                        tmp += ' ';
                    }
                    tmp += words[k];
                }
            } else {
                for (int k = i + 1; k < j; k++) {
                    tmp += ' ';
                    tmp += words[k];
                }
                while (tmp.length() < L) {
                    tmp += ' ';
                }
            }
            ans.push_back(tmp);
            i = j - 1;
        }
        return ans;
    }
};