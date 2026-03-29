class Solution {
public:
int f(vector<int>&nums, int i, int target, int sum,vector<vector<int>>&dp,int sum2){
     
    if(i==nums.size()){
       
        if(sum==target){
            return 1;
        }return 0;}
        if(dp[i][sum+sum2]!=-1){
            return dp[i][sum+sum2];
        }
        
        int one=f(nums,i+1,target,sum+nums[i],dp,sum2);
        int two=f(nums,i+1,target,sum-nums[i],dp,sum2);
        return dp[i][sum+sum2]=two+one;
    }


    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        vector<vector<int>>dp(nums.size(),vector<int>((2*sum+1),-1));
        int ans =f(nums,0,target,0,dp,sum);
        return ans;
    }
};
