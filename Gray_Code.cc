class Solution
{
public:
    /*
     * for reference: http://en.wikipedia.org/wiki/Gray_code.
     */
    vector<int> grayCode (int n) {
        vector<int> ret;
        int size = 1 << n;
        for (int i = 0; i < size; i++) {
            ret.push_back((i >> 1) ^ i);
        }
        return ret;
    }
};