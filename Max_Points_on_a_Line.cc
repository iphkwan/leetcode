/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.size() <= 1)
            return points.size();
        
        unordered_map<double, int> hash;
        double fSlope;
        int ret = 0, iVertical, iSame, iMaxValue;
        for (int i = 0; i < points.size(); i++) {
            hash.clear();
            iVertical = iSame = iMaxValue = 0;
            for (int j = 0; j < points.size(); j++) {
                if (points[i].x == points[j].x) {
                    //same
                    if (points[i].y == points[j].y) {
                        iSame++;
                    } 
                    //vertical
                    else {
                        iVertical++;
                    }
                }
                else {
                    fSlope = (points[i].y - points[j].y) * 1.0 / (points[i].x - points[j].x);
                    hash[fSlope]++;
                    iMaxValue = max(iMaxValue, hash[fSlope]);
                }
            }
            ret = max(ret, max(iMaxValue, iVertical) + iSame);
        }
        return ret;
    }
};
