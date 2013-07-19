class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> helper;
        string tmp, ans = "";
        int plen = path.length();
        int st_pos = 0, end_pos;
        while (st_pos < plen) {
            while (st_pos < plen && path[st_pos] == '/') {
                st_pos++;
            }
            end_pos = st_pos + 1;
            while (end_pos < plen && path[end_pos] != '/') {
                end_pos++;
            }
            tmp = path.substr(st_pos, end_pos - st_pos);
            if (tmp == "..") {
                if (helper.size() > 0) {
                    helper.pop_back();
                }
            } else if (tmp != "." && tmp.length() > 0) {
                helper.push_back(tmp);
            }
            st_pos = end_pos + 1;
        }
        for (int i = 0; i < helper.size(); i++) {
            ans += '/';
            ans += helper[i];
        }
        if (ans.length() == 0) {
            return "/";
        }
        return ans;
    }
};