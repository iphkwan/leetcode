class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        set<int> hm;
        int n = num.size();
        for (int i = 0; i < n; i++)
            hm.insert(num[i]);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 1;
            int tmp = num[i];
            if (hm.find(tmp) == hm.end())
                continue;
            hm.erase(tmp);
            while (hm.find(++tmp) != hm.end()) {
                cnt++;
                hm.erase(tmp);
            }
            tmp = num[i];
            while (hm.find(--tmp) != hm.end()) {
                cnt++;
                hm.erase(tmp);
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};