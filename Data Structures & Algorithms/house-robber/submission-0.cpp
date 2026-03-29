class Solution {
public:
int fun(vector<int>&nums, int i, int n, vector<int>&dp){
    if(i>=n){
        return 0;
    }
    if(dp[i]!=-1)return dp[i];
    int nt=fun(nums, i+1, n, dp);
    int t=nums[i]+fun(nums, i+2, n, dp);
    return dp[i]=max(nt,t);
}

    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int>dp(nums.size(),-1);
        return fun(nums, 0, nums.size(),dp);
    }
};
