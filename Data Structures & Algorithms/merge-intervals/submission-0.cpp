class Solution {
public:
static bool comp(vector<int>&a, vector<int>&b){
    return a[0]<b[0];
}
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
       
        sort(intervals.begin(),intervals.end(), comp);
        int i=0;
        int rmax=intervals[0][1];
        int start=intervals[0][0];
        int n=intervals.size();
        while(i<intervals.size()){

             rmax=intervals[i][1];
            start=intervals[i][0];
            int j=i;
            while(i<n){
                int temp=intervals[i][0];
                if(temp<=rmax){
                    rmax=max(rmax, intervals[i][1]);
                    if(i==n-1){
                         ans.push_back({start,rmax});
                    }
                }else{
                 
                    ans.push_back({start,rmax});
break;
                }
                i++;
            }
       

        }
        return ans;
    }
};
