class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = height.size();
        if (len == 0) {
            return 0;
        }
        stack<int> st;
        int ans = 0, curHeight, width;
        for (int i = 0; i < len; i++) {
            while (!st.empty() && height[st.top()] >= height[i]) {
                curHeight = height[st.top()];
                st.pop();
                width = (st.empty() ? i : i - st.top() - 1);
                ans = max(ans, curHeight * width);
            }
            st.push(i);
        }
        while (!st.empty()) {
            curHeight = height[st.top()];
            st.pop();
            width = (st.empty() ? len : len - st.top() - 1);
            ans = max(ans, curHeight * width); 
        }
        return ans;
    }
};