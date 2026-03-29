class Solution {
public:
int fun(vector<int>&nums, int i,int sum,int total,vector<vector<int>>&dp){
    if(i==nums.size()-1){
        if(sum==(total/2)){
            return 1;
        }
        return 0;
    }
    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }
    bool take=fun(nums,i+1,sum+nums[i], total,dp);
    bool ntake=fun(nums,i+1,sum,total,dp);
    return dp[i][sum]=take||ntake;
}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2==1)return false;
        vector<vector<int>>dp(nums.size(), vector<int>(sum+1,-1));

        return fun(nums,0,0,sum,dp);
    }
};
