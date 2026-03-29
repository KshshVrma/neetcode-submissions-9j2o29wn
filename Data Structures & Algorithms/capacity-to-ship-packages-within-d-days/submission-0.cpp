class Solution {
public:
bool fun(int mid, vector<int>& weights, int days){
int count=0;
int tempsum=0;
int i=0;
while(i<weights.size()){
    if(tempsum+weights[i]>mid ){
        count++;
        tempsum=weights[i];
    }else{
        tempsum+=weights[i];
    }

    if( i==weights.size()-1){
        count++;
    }
    i++;
}
return count<=days;

}
    int shipWithinDays(vector<int>& weights, int days) {
        int ans=INT_MAX;
        int sum=0;
        int mini=INT_MIN;
        for(int i;i<weights.size();i++){
            mini=max(mini, weights[i]);
            sum+=weights[i];
        }
        int l=mini;
        int r=sum;
        while(l<=r){
            int mid=(l+r)/2;
            if(fun(mid, weights, days)){
                ans=min(ans, mid);
                r=mid-1;
            }else{
                l=mid+1;
            }
     
        }
        return ans;
    }
};