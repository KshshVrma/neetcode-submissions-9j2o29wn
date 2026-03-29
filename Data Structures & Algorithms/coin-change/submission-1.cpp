class Solution {
public:
int fun(vector<int>&coins, int amount, long sum, vector<long>&dp){
    if(sum==amount)return 0;
    if(sum>amount)return 1e9;
    if(dp[sum]!=-1)return dp[sum];

    int coinss=0;
    int mini=INT_MAX;

    for(int i=0;i<coins.size();i++){
        coinss=1+fun(coins, amount, sum+coins[i], dp);
        if(coinss<mini){
            mini=coinss;
        }

    }
    return dp[sum]=mini;

}

    int coinChange(vector<int>& coins, int amount) {
       vector<long>dp(amount, -1);
      int k=fun(coins, amount, 0, dp);
      if(k>=1e9)return -1;
      return k;
    }
};
