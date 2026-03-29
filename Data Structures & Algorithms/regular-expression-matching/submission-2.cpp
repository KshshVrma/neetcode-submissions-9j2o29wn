class Solution {
public:
bool fun(string &s, string &p, int i, int j, vector<vector<int>>&dp){
    if(j>p.size())return false;
    if(j==p.size()){
        if(i==s.size()){
            return true;
        }
        return false;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    bool firstmatches=false;
    if( i<s.size() && (s[i]==p[j] || p[j]=='.')){
        firstmatches=true;
    }
    if( j+1<p.size() && p[j+1]=='*'){
        bool nt=  j+2<=p.size() && fun(s, p, i, j+2,dp);

        bool t= firstmatches && fun(s, p, i+1, j,dp);
        return dp[i][j]=nt || t;

    }

return dp[i][j]=firstmatches && fun(s, p, i+1, j+1,dp);
    
}
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size()+1, vector<int> (p.size()+  1,-1));
        return fun(s, p, 0,0,dp);
    }
};
