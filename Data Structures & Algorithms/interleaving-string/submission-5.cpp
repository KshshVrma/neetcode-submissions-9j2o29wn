class Solution {
public:
bool fun(string s1, string s2, string s3 , int i, int j, vector<vector<int>>&dp){
if(i==s1.size() && j==s2.size() && i+j==s3.size())return true;

if(i==s1.size() && (j<s2.size() && s2[j]!=s3[i+j]))return false;
if(j==s2.size() && (i<s1.size() && s1[i]!=s3[i+j]))return false;
if(i+j==s3.size() && (i!=s1.size() || j!=s2.size()))return false;

if(dp[i][j]!=-1)return dp[i][j];

bool one=false, two=false;
if(s1[i]==s3[i+j]){
    one= fun(s1,s2,s3, i+1, j, dp);
}
if(s2[j]==s3[i+j]){
    two= fun(s1, s2, s3, i, j+1, dp);
}
return dp[i][j]=one || two;
}
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())return false;
   
      
        // vector<vector<vector<int>>>dp(s1.size()+1, vector<vector<int>>(s2.size()+1, 
        // vector<int>(s3.size()+1, -1)));
        vector<vector<int>> dp(s1.size()+1, vector<int> (s2.size()+1, -1));
        return fun(s1, s2, s3, 0, 0, dp);
    }
};
