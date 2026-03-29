class Solution {
public:
bool fin(string temp, vector<string>& wordDict){
    for(int i=0;i<wordDict.size();i++){
        if(wordDict[i]==temp)return true;
    }
    return false;
}
bool fun(string s, vector<string>& wordDict, int ind,vector<int>&dp){
    if(ind==s.size()){
return true;
    }
    if(dp[ind]!=-1)return dp[ind];
bool boo=false;
    for(int i=ind;i<s.size();i++){
        string temp=s.substr(ind,i-ind+1);
        if(fin(temp, wordDict)){
             if(fun(s, wordDict, i+1,dp)){
                boo=true;
             }
        }
    }
    return dp[ind]=boo;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size(),-1);
        return fun(s,wordDict, 0,dp);
    }
};
