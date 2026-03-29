class Solution {
public:
int fun(string word1, string word2, int n, int m,vector<vector<int>>&dp){
    if(n<0){
        return m+1;
    }
    if(m<0){
        return n+1;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    if(word1[n]==word2[m]){
        return fun(word1,word2, n-1,m-1,dp);
    }
    int ins=fun(word1,word2, n-1,m,dp)+1;
    int del=fun(word1,word2, n, m-1,dp)+1;
    int rep=fun(word1,word2, n-1,m-1,dp)+1;
    return dp[n][m]=min(ins,min(del,rep));
}
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        return fun(word1,word2, word1.size()-1, word2.size()-1,dp);
    }
};
