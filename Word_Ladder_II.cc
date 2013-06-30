class Solution {
public:
    vector<string> q;
    vector<int> dep;
    vector<vector<int>> fa;
    vector<vector<string>> ans;
    unordered_map<string, int> mp;
    void dfs(vector<string> &tmp, int cnt) {
        if (cnt == -1) {
            ans.push_back(vector<string>(0));
            for (int i = tmp.size() - 1; i >= 0; i--)
                ans.back().push_back(tmp[i]);
            return;
        }
        for (int i = 0; i < fa[cnt].size(); i++) {
            tmp.push_back(q[cnt]);
            dfs(tmp, fa[cnt][i]);
            tmp.pop_back();
        }
    }

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        q.clear(), dep.clear(), fa.clear(), ans.clear(), mp.clear();
        q.push_back(start);
        dep.push_back(1);
        fa.push_back(vector<int>(0));
        fa.back().push_back(-1);
        int pt = 0, cntStep, ansStep = -1;
        while (pt < q.size()) {
            string nxt, str = q[pt];
            cntStep = dep[pt];
            if (ansStep != -1 && cntStep == ansStep)
                break;
            for (int i = 0; i < str.length(); i++)
                for (char j = 'a'; j <= 'z'; j++) {
                    if (str[i] == j)
                        continue;
                    nxt = str;
                    nxt[i] = j;
                    if (nxt == end) {
                        ansStep = cntStep + 1;
                        vector<string> tmp(0);
                        tmp.push_back(end);
                        dfs(tmp, pt);
                        continue;
                    }
                    if (dict.count(nxt)) {
                        if (mp[nxt] == 0) {
                            q.push_back(nxt);
                            dep.push_back(cntStep + 1);
                            fa.push_back(vector<int>(0));
                            fa.back().push_back(pt);
                            mp[nxt] = fa.size() - 1;
                        }
                        else if (dep[ mp[nxt] ] == cntStep + 1)
                            fa[ mp[nxt] ].push_back(pt);
                    }
                }
            pt++;
        }
        return ans;
    }
};