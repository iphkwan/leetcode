/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(Interval A, Interval B) {
    if (A.start != B.start) {
        return A.start < B.start;
    }
    return A.end < B.end;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> ans;
        int st_pos = 1, end_pos = 0;
        for (int i = 0; i < intervals.size(); i++) {
            if (st_pos > end_pos) {
                st_pos = intervals[i].start;
                end_pos = intervals[i].end;
            } else {
                if (intervals[i].start <= end_pos) {
                    end_pos = max(end_pos, intervals[i].end);
                } else {
                    ans.push_back(Interval(st_pos, end_pos));
                    st_pos = intervals[i].start;
                    end_pos = intervals[i].end;
                }
            }
        }
        if (st_pos <= end_pos) {
            ans.push_back(Interval(st_pos, end_pos));
        }
        return ans;
    }
};