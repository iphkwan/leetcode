class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int f[10], num[10];
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1] * i;
        }
        bool vis[10];
        memset(vis, false, sizeof(vis));
        k--;
        int i, j, tmp;
        for (i = 0; i < n; i++) {
            tmp = k / f[n - 1 - i];
            for (j = 0; j < n; j++) {
                if (!vis[j]) {
                    if (tmp == 0)   break;
                    tmp--;
                }
            }
            num[i] = j + 1;
            vis[j] = true;
            k %= f[n - 1 - i];
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            ans += (char)(num[i] + '0');
        }
        return ans;
    }
};