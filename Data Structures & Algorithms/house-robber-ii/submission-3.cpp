class Solution {
public:
int fun(int i, int n, vector<int>&nums,vector<int>&dp){
    if(i>=n)return 0;
    if(dp[i]!=-1){
        return dp[i];
    }
    int nt=fun(i+1,n,nums,dp);
    int t=fun(i+2,n,nums,dp)+nums[i];
    return dp[i]=max(nt,t);
}
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int>dp(nums.size(),-1);
        vector<int>dpp(nums.size(),-1);
        return max(fun(0, nums.size()-1,nums,dp), fun(1,nums.size(),nums,dpp));
    }
};
