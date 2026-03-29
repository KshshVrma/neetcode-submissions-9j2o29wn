class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;

        int lmax=0;int rmax=0;
        vector<int>lmaxi;
        vector<int>rmaxi(height.size(),-1);
        for(int i=0;i<height.size();i++){
            lmax=max(lmax, height[i]);
            lmaxi.push_back(lmax);
        }

        for(int i=height.size()-1;i>=0;i--){
            rmax=max(rmax, height[i]);
            rmaxi[i]=rmax;
        }
int sum=0;
        for(int i=0;i<height.size();i++){
            int currmax=min(lmaxi[i],rmaxi[i]);
if(height[i]<currmax){
    sum+=currmax-height[i];
}
        }
        return sum;
    }
};
