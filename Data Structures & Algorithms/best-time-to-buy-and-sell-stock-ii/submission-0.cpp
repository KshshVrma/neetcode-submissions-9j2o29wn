class Solution {
public:
int fun(vector<int>&prices, int i, int buy, vector<vector<int>>&dp){
    if(i==prices.size()){
        return 0;
    }
    if(dp[i][buy]!=-1){
        return dp[i][buy];
    }
    int one=0,two=0;
    if(buy){
 one=-prices[i]+fun(prices, i+1, 0,dp);
 one=max(one, fun(prices,i+1,1,dp));
    }else{
        two=prices[i]+fun(prices,i,1,dp);
        two=max(two, fun(prices,i+1,1,dp));
    }
    return dp[i][buy]=max(one, two);
}
    int maxProfit(vector<int>& prices) {
         int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
        return fun(prices, 0, 1, dp);
    }
};