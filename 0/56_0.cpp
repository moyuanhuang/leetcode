/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool operator<(const Interval& l, const Interval& r)
{
	return l.start < r.start;
}


class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
    	vector<Interval> ret;
        if(intervals.empty())	return ret;
        sort(intervals.begin, intervals.end);
        int l = intervals[0].start, r = intervals[0].end;
        for(int i = 0; i < intervals.size(); i++)
        {
        	if(intervals[i].start > r)
        	{
        		Interval cur(intervals[0]);
        		cur.start = l;
        		cur.end = r;
        		ret.push_back(cur);
        		l = intervals[i].start;
        		r = intervals[i].end;
        		continue;
        	}
        	else
        		r = intervals[i].end > r? intervals[i].end: r;
        }
        return ret;
    }
};