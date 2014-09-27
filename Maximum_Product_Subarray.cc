class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n <= 0) return 0;
        int iMaxProductEndByPrePos = A[0], iMaxProductEndByCurrentPos;
        int iMinProductEndByPrePos = A[0], iMinProductEndByCurrentPos;
        int ret = A[0];
        for (int i = 1; i < n; i++) {
            iMaxProductEndByCurrentPos = max(max(iMaxProductEndByPrePos * A[i], iMinProductEndByPrePos * A[i]), A[i]);
            iMinProductEndByCurrentPos = min(min(iMaxProductEndByPrePos * A[i], iMinProductEndByPrePos * A[i]), A[i]);
            ret = max(ret, iMaxProductEndByCurrentPos);
            iMaxProductEndByPrePos = iMaxProductEndByCurrentPos;
            iMinProductEndByPrePos = iMinProductEndByCurrentPos;
        }
        return ret;
    }
};
