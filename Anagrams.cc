class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<string, vector<string> > mp;
        vector<string> ans;
        string tmp;
        for (int i = 0; i < strs.size(); i++) {
            tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(strs[i]);
        }
        for (map<string, vector<string> >::iterator p = mp.begin(); p != mp.end(); p++) {
            if ((p->second).size() > 1) {
                for (int i = 0; i < (p->second).size(); i++) {
                    ans.push_back((p->second)[i]);
                }
            }
        }
        return ans;
    }
};