class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 2) {
            return 1;
        }
        Mat ans;
        ans.a[0][0] = ans.a[1][0] = ans.a[0][1] = 1;
        ans = Power(ans, n);
        return ans.a[0][0];
    }
private:
    struct Mat {
        int a[2][2];
        Mat() {
            memset(a, 0, sizeof(a));
        }
    };
    Mat Mul(Mat &A, Mat &B) {
        Mat ret;
        for (int k = 0; k < 2; k++) {
            for (int i = 0; i < 2; i++) {
                if (A.a[i][k] == 0) {
                    continue;
                }
                for (int j = 0; j < 2; j++) {
                    if (B.a[k][j] == 0) {
                        continue;
                    }
                    ret.a[i][j] += A.a[i][k] * B.a[k][j];
                }
            }
        }
        return ret;
    }
    Mat Power(Mat A, int k) {
        Mat ret;
        ret.a[0][0] = ret.a[1][1] = 1;
        while (k) {
            if (k & 1) {
                ret = Mul(ret, A);
            }
            k >>= 1;
            A = Mul(A, A);
        }
        return ret;
    }
};