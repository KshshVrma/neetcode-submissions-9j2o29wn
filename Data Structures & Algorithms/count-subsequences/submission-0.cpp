class Solution {
public:
int fun(int i, string s, string t, int j, vector<vector<int>> &dp){

    if(j==t.size())return 1;
    if(i==s.size())
    return 0;

if(dp[i][j]!=-1)return dp[i][j];

int count=0;


count+=fun(i+1, s, t, j, dp);
if(j < t.size() && s[i]==t[j])
count+=fun(i+1, s, t, j+1, dp);
return dp[i][j]=count;
}
    int numDistinct(string s, string t) {
        string temp="";
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return fun( 0, s, t,0,dp);
    }
};

