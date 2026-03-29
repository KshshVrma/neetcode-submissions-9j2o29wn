class Solution {
public:
int fun(int i, int n, string s, vector<int>&dp){
    if(i==n)return 1;
    if(i>n)return 0;
if(s[i]=='0')return 0;
if(dp[i]!=-1)return dp[i];
    int one=fun(i+1, n, s, dp);
    if(i+1<n && (s[i]=='1') or (s[i]=='2' && s[i+1]>='0' && s[i+1]<'7')){
        one+=fun(i+2, n,s, dp);
    }
    return dp[i]=one;
}
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n, -1);
        if(s[0]=='0')return 0;
        return fun(0,n,s,dp);
    }
};
