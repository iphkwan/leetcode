/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> ans;
        int st_pos = 1, end_pos = 0, cur = 0;
        while (cur < intervals.size() && intervals[cur].end < newInterval.start) {
            ans.push_back(intervals[cur++]);
        }
        if (intervals.size() == cur) {
            ans.push_back(newInterval);
            return ans;
        }
        if (newInterval.end < intervals[cur].start) {
            st_pos = newInterval.start;
            end_pos = newInterval.end;
        } else {
            st_pos = min(newInterval.start, intervals[cur].start);
            end_pos = max(newInterval.end, intervals[cur++].end);
        }
        while (cur < intervals.size() && intervals[cur].start <= end_pos) {
            end_pos = max(end_pos, intervals[cur++].end);
        }
        ans.push_back(Interval(st_pos, end_pos));
        while (cur < intervals.size()) {
            ans.push_back(intervals[cur++]);
        }
        return ans;
    }
};