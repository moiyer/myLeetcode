/*

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

*/

//2013/7/3 11:07:25
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 //水题，注意sort的用法
class Solution {
public:
	struct myclass {
		bool operator() (Interval i,Interval j) { return (i.start < j.start);}
	} myobject;

    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
  		if(intervals.size() <= 1)return intervals;

  		sort(intervals.begin(), intervals.end(), myobject);

  		std::vector<Interval>::iterator it;
  		std::vector<Interval> ret;
  		ret.push_back(intervals[0]);
  		for(it = intervals.begin() + 1; it != intervals.end(); ++it)
  		{
  			if(it->start <= ret.back().end)
  			{
  				if(it->end > ret.back().end)ret.back().end = it->end;
  			}
  			else ret.push_back(*it);
  		}

  		return ret;
    }
};