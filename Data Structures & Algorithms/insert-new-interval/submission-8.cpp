class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        if(intervals.size()==0){
            ans.push_back(newInterval);
            return ans;
        }
        int i=0;
        int count=0;
        while(i<intervals.size()){
            if(intervals[i][1]<newInterval[0] || intervals[i][0]>newInterval[1]){
                if(intervals[i][0]>newInterval[1] ){
                    
                    if(count==0){

                    
                        count=2;
                        ans.push_back(newInterval);
                  
                    }
                }
                ans.push_back(intervals[i]);
                    if(intervals[i][1]<newInterval[0] && i==intervals.size()-1){
                         ans.push_back(newInterval);
                         return ans;
                    }
                i++;
                continue;

            }
            int currleft=min(newInterval[0],intervals[i][0]);
            int currright=intervals[i][1];
            while(i<intervals.size() && intervals[i][0]<=newInterval[1]){
                currright=max(currright,max(newInterval[1],intervals[i][1]));
                i++;

            }
            count=1;
            ans.push_back({currleft,currright});
        }
        return ans;
    }
};
