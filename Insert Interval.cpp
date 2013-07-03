/*

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

*/

//2013/7/3 19:13:20
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 //水题，自己没写，注意二分查找和vector.insert()
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {

        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int insertp = findPosition(intervals, newInterval);
        intervals.insert(intervals.begin() + insertp, newInterval);
        for (int i = 0; i < intervals.size() - 1; ++i) {
            if (intervals[i].end >= intervals[i + 1].start) {
                if (intervals[i].end < intervals[i + 1].end) {
                    intervals[i].end = intervals[i + 1].end;
                }
                intervals.erase(intervals.begin() + i + 1);
                --i;
            }
        }
        return intervals;
    }

    int findPosition(vector<Interval> &intervals, Interval newInterval) {
        int low = 0;
        int high = intervals.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (intervals[mid].start == newInterval.start) return mid;
            else if (intervals[mid].start < newInterval.start) low = mid + 1;//注意要加一
            else high = mid - 1;//注意要减一
        }
        return low;
    }
};