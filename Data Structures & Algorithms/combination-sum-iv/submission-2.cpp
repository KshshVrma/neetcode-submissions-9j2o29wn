class Solution {
public:
int fun(vector<int>&nums, int i, int sum, int target,vector<int>&dp){
    if(sum>target)return 0;
    if(i==nums.size()){
        if(sum==target){
            return 1;
        }return 0;
    }
    if(dp[sum]!=-1){
        return dp[sum];
    }
    int one= fun(nums, i+1, sum, target,dp);
    int two=fun(nums, 0, sum+nums[i], target,dp);
    return dp[sum]=one+two;
}
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1, -1);
        return fun(nums, 0,0, target,dp);
    }
};