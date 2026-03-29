class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {


          for(int i=0;i<intervals.size();i++){
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<" ";
        }
        cout<<endl;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<" ";
        }

int count=0;
if(intervals.size()==1)return 0;

int i=0;int j=1;

       while(j<intervals.size() && i<intervals.size()){

int one=intervals[i][0];
int two=intervals[i][1];

int three=intervals[j][0];
int four=intervals[j][1];

if(two>three){
    if(four<two){
i=j;
j++;
    }else{
j++;
    }

    
    count++;
}else{
    i=j;
    j++;
}
       }
        return count;
    }
};
