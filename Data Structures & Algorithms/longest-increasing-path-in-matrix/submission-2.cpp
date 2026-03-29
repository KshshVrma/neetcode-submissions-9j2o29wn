class Solution {
public:

int dfs(vector<vector<int>>&matrix, int r, int c, int prev,
vector<vector<int>>&dp){
    int n=matrix.size();
    int m=matrix[0].size();

    if(r<0 || r>=n || c <0 || c>= m || matrix[r][c]<=prev)return 0;

    if(dp[r][c]!=-1)return dp[r][c];

    int row[]={0,-1, 0,1};
    int col[]={-1,0,1,0};
    int curr=1;
    for(int i=0;i<4;i++){
        int nrow=r+row[i];
        int ncol=c+col[i];
curr=max(curr,1+ dfs(matrix, nrow, ncol, matrix[r][c], dp));
    }
    return dp[r][c]=curr;


}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans=INT_MIN;

    vector<vector<int>>dp(matrix.size(), vector<int>(matrix[0].size(),-1));
        

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){

                ans=max(ans, dfs(matrix,i,j, INT_MIN, dp));

            }
        }

        return ans;
    }
};
