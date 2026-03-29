class Solution {
public:
int fun(int amount, vector<int>&coins, int sum, int it, vector<vector<int>>&dp){
    if(sum>amount)return 0;
    if(sum==amount)return 1;
    if(dp[sum][it]!=-1){
        return dp[sum][it];
    }
    int t=0;
    for(int i=it;i<coins.size();i++){
       
       t+=fun(amount, coins, sum+coins[i], i,dp);
        
    }
    return dp[sum][it]=t;
}
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(amount+1, vector<int>(coins.size(),-1));
        return fun(amount, coins, 0,0,dp);
    }
};
