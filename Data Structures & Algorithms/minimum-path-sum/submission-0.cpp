class Solution {
public:
int fun(int i,int j ,vector<vector<int>>& grid , vector<vector<int>>&dp){
    if(i==grid.size()|| j==grid[0].size()){
        return 1e9;
    }
    if(i==grid.size()-1 && j==grid[0].size()-1){
        return grid[grid.size()-1][grid[0].size()-1];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int one=fun(i+1,j,grid,dp);
    int two=fun(i,j+1,grid,dp);
    return dp[i][j]= grid[i][j] + min(one,two);

}
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));

        return fun(0,0,grid,dp);
    }
};