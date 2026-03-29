class Solution {
public:
int f(int mid, vector<int>&piles, int h){
int count=0;
for(int i=0;i<piles.size();i++){
    if(piles[i]>mid){
        if(piles[i]%mid){
            count+=piles[i]/mid +1;
        }else{
            count+=piles[i]/mid;
        }

    }else{
        count++;
    }
}
if(count<=h){
    return 1;
}return 0;

}
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=0;
        for(int i=0;i<piles.size();i++){
            maxi=max(maxi,piles[i]);
        }
        int low=1;
        int high=maxi;
        int ans=maxi;
        while(low<=high){
int mid=(low+high)/2;
if(f(mid,piles,h)){
    ans=mid;
    high=mid-1;
}else{
    low=mid+1;
}
        }
        return ans;
    }
};
