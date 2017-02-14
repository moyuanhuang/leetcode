/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool operator<(const Interval& a, const Interval& b)
{
	return a.start < b.start;
}

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
	{
		vector<Interval> ret;
		for(int i = 0; i < intervals.size(); i++)
		    ret.push_back(intervals[i]);
		if(intervals.size() == 0)
		{
			ret.push_back(newInterval);
			return ret;
		}
		sort(ret.begin(), ret.end());
		int nl = newInterval.start, nr = newInterval.end;
		for(int i = 0; i < ret.size(); i++)
		{
			int l = intervals[i].start, r = intervals[i].end;
			if((nl <= r and nr >= r) or (nl <= l and nr >= l))
			{
				nl = nl < l? nl: l;
				nr = nr > r? nr: r;
				ret.erase(intervals.begin()+i);
				i--;
			}
			else if ((nr < l) or (nl > r))
			{
				break;
			}
			else if(nl > l and nr < r)
			    return intervals;
		}
		newInterval.start = nl;
		newInterval.end = nr;
		ret.push_back(newInterval);
		return ret;
	}
};