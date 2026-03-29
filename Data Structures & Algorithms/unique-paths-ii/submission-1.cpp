class Solution {
public:
int fun(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp){
    if(i==grid.size()|| j==grid[0].size())return 0;
    if(i==grid.size()-1 && j==grid[0].size()-1){
        if(grid[i][j]==1)return 0;
        return 1;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int down=0;
    if(i+1<grid.size() && grid[i+1][j]!=1){
        down=fun(i+1,j, grid,dp);
    }

     int right=0;
    if(j+1<grid[0].size() && grid[i][j+1]!=1){
        right=fun(i,j+1, grid,dp);
    }
    return dp[i][j]=down+right;

}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>>dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        if(obstacleGrid[0][0]==1)return 0;
        return fun(0,0, obstacleGrid,dp);
    }
};