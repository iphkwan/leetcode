class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        int x, y;
        for (int i = 0; i < tokens.size(); i++) {
            if ((tokens[i][0] >= '0' && tokens[i][0] <= '9') || (tokens[i].length() > 1)) {
                x = 0;
                int j = 0;
                if (tokens[i][0] == '-')    j++;
                for (; j < tokens[i].length(); j++)
                    x = x * 10 + (tokens[i][j] - '0');
                if (tokens[i][0] == '-')    x = -x;
                st.push(x);
            } else {
                if (st.size() < 2)  return ERROR_CODE;
                x = st.top(), st.pop();
                y = st.top(), st.pop();
                if (tokens[i][0] == '+') st.push(x + y);
                else if (tokens[i][0] == '-')    st.push(y - x);
                else if (tokens[i][0] == '*')    st.push(y * x);
                else if (tokens[i][0] == '/' && x != 0)  st.push(y / x);
                else    return ERROR_CODE;
            }
        }
        return st.empty() ? 0 : st.top();
    }
private:
    int ERROR_CODE = -1;
};
