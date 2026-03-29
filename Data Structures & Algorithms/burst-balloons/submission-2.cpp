class Solution {
public:
int fun(vector<int>&arr, int l, int r,vector<vector<int>>&dp){
    if(l+1>=r){
return 0;
    }
    if(dp[l][r]!=-1)return dp[l][r];
int maxi=0;
    for(int i=l+1;i<r;i++){
        int tot=arr[l]* arr[i]* arr[r];
        int one=fun(arr, l,i,dp);
        int two=fun(arr,i,r,dp);
        maxi=max(maxi,(tot+one+two));

    }
    return dp[l][r]=maxi;
}
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(n+2,1);
        for(int i=0;i<nums.size();i++){
            arr[i+1]=nums[i];
        }
        vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),-1));
        return fun(arr, 0, n+1,dp);
    }
};
