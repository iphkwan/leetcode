class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<string> q;
        queue<int> dep;
        unordered_map<string, int> hm;
        q.push(start);
        dep.push(1);
        hm[start] = 1;
        string str, nxt;
        int cntStep;
        while (!q.empty()) {
            str = q.front();
            q.pop();
            cntStep = dep.front();
            dep.pop();
            if (str == end)
                return cntStep;
            for (int i = 0; i < str.length(); i++)
                for (char j = 'a'; j <= 'z'; j++) {
                    if (str[i] == j)
                        continue;
                    nxt = str;
                    nxt[i] = j;
                    if (dict.count(nxt) && hm[nxt] == 0) {
                        hm[nxt] = 1;
                        q.push(nxt);
                        dep.push(cntStep + 1);
                    }
                }
        }
        return 0;
    }
};