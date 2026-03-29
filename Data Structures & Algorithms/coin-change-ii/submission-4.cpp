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

int fun2(int amount, vector<int>&coins, int sum, int it, vector<vector<int>>&dp){
    if(sum>amount)return 0;
    if(sum==amount)return 1;
    if(it==coins.size()){
          if(sum==amount)return 1;
          return 0;
    }
    if(dp[sum][it]!=-1){
        return dp[sum][it];
    }
    int t=0;
    t+=fun2(amount, coins, sum, it+1, dp);
    t+=fun2(amount, coins, sum+coins[it], it, dp);
   
    return dp[sum][it]=t;
}

    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(amount+1, vector<int>(coins.size(),-1));
        return fun2(amount, coins, 0,0,dp);
    }
};
