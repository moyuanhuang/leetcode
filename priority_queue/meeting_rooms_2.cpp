// leetcode 253. Meeting Rooms II
// medium

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

typedef pair<int, int> timestamp;
struct comparator {
    bool operator() (timestamp a, timestamp b){
        if (a.first == b.first){
            return a.second > b.second;
        }
        return a.first > b.first;

    }
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        priority_queue<timestamp, vector<timestamp>, comparator> pq;
        for(Interval intv : intervals){
            pq.push({intv.start, 1});
            pq.push({intv.end, -1});
        }

        int cur = 0, result = 0;
        while(!pq.empty()){
            timestamp temp = pq.top();
            pq.pop();
            if(temp.second == 1){
                cur++;
                result = max(result, cur);
            } else {
                cur--;
            }
        }
        return result;
    }
};
