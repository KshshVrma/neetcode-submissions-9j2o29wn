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
static bool cmp(const Interval a, const Interval b){
    if(a.start==b.start)return a.end<b.end;
    else return a.start<b.start;
}
    bool canAttendMeetings(vector<Interval>& intervals) {
        bool ans=true;
        int i=0;
        sort(intervals.begin(),intervals.end(), cmp);
        if(intervals.size()==0)return true;
        int upper=intervals[0].end;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i].start<upper){
                return false;
            }
            upper=max(upper, intervals[i].end);

        }
        return ans;
    }
};
