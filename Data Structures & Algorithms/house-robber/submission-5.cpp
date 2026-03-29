class Solution {
public:
int fun(vector<int>&nums, int i, int n, vector<int>&dp){
    if(i>=n){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int ntake=fun(nums, i+1, n, dp);
    int take=fun(nums, i+2, n, dp)+ nums[i];
    return dp[i]=max(take, ntake);
}
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int>dp(nums.size(),-1);
        return fun(nums, 0, nums.size(), dp);
    }
};
