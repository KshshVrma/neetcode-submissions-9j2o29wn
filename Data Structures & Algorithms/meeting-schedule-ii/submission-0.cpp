/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
static bool cmp(Interval& a, Interval &b){
    return a.start<b.start;
}
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        priority_queue<int, vector<int>, greater<int>> q;

        for(int i=0;i<intervals.size();i++){
            int one=intervals[i].start;
            int two=intervals[i].end;

            if(!q.empty() && one>=q.top()){
                q.pop();
            }
            q.push(two);

        }

        return q.size();
    }
};
