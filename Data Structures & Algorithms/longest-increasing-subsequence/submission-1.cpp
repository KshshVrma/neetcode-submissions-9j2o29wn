class Solution {
public:
int fun(vector<int>&nums, int i, int prev, vector<vector<int>>&dp){
    if(i>nums.size()){
        return 0; 
    }
    if(i==nums.size())return 0;
    if(dp[i][prev+1]!=-1){
        return dp[i][prev+1];
    }
int take=0;
    if(prev==-1 || nums[i]>nums[prev]){
        take=1+fun(nums, i+1,i,dp);
    }
    int nt=fun(nums, i+1, prev,dp);
    return dp[i][prev+1]=max(nt,take);
}
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        int k=fun(nums, 0,-1,dp);
        return k;
    }
};
