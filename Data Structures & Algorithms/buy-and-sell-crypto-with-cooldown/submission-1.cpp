class Solution {
public:
int fun(vector<int> &prices, int i, int buy, vector<vector<int>>&dp){
    if(i>=prices.size())return 0;
int profit=0;
int hold=0;
int sell=0;
if(dp[i][buy]!=-1)return dp[i][buy];
    
    if(buy){
        hold=max(hold, fun(prices,i+1,buy,dp));
        sell=max(sell, -prices[i]+ fun(prices,i+1,0,dp));

    }else{
        hold=max(hold, fun(prices,i+1,0,dp));
        sell=max(sell, prices[i]+fun(prices,i+2,1,dp));
    }
    return dp[i][buy]= max(hold, sell);
}


    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(), vector<int>(2,-1));
       return fun(prices,0,1,dp);
    }
};
