class Solution {
public:
    int row, col;
    vector<vector<int>> vis;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    bool judge(int x, int y) {
        return (x >= 0 && x < row && y >= 0 && y < col);
    }
    struct Node {
        int x, y;
        Node(){}
        Node(int a, int b) {
            x = a, y = b;
        }
    };
    
    bool bfs(vector<vector<char>> &g, vector<Node> &ans, int x, int y) {
        bool flag = true;
        queue<Node> q;
        vis[x][y] = 1;
        ans.push_back(Node(x, y));
        q.push(Node(x, y));
        Node t;
        int tx, ty;
        while (!q.empty()) {
            t = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                tx = t.x + dx[i];
                ty = t.y + dy[i];
                if (judge(tx, ty) == false) {
                    flag =false;
                    continue;
                }
                if (vis[tx][ty] == 0 && g[tx][ty] == 'O') {
                    vis[tx][ty] = 1;
                    ans.push_back(Node(tx, ty));
                    q.push(Node(tx, ty));
                }
            }
        }
        return flag;
    }
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        row = board.size();
        if (row == 0)
            return;
        col = board[0].size();
        if (col == 0)
            return;
        vector<int> tmp;
        tmp.clear(), vis.clear();
        for (int i = 0; i < col; i++)
            tmp.push_back(0);
        for (int i = 0; i < row; i++)
            vis.push_back(tmp);
        vector<Node> ans;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) {
                ans.clear();
                if (vis[i][j] == 0 && board[i][j] == 'O' && bfs(board, ans, i, j)) {
                    for (int k = 0; k < ans.size(); k++)
                        board[ ans[k].x ][ ans[k].y ] = 'X';
                }
            }
        return;
    }
};