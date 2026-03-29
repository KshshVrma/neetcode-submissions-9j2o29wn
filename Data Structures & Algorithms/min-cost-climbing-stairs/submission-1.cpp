class Solution {
public:
int f(int i, vector<int>&cost,vector<int>&dp){
    if(i>=cost.size()){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int take=cost[i]+f(i+1,cost,dp);
    int takenext=cost[i]+f(i+2,cost,dp);
    return dp[i]=min(take,takenext);
}
    int minCostClimbingStairs(vector<int>& cost) {
        
int ans=-1;
vector<int>dp(cost.size(),-1);
int one=f(0, cost,dp);
int two =f(1,cost,dp);
return min(one,two);

    }
};
