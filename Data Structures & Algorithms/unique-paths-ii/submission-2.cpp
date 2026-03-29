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

int fun2(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp){
    dp[grid.size()-1][grid[0].size()-1]=1;

    for(int i=grid.size()-1;i>=0;i--){
        for(int j=grid[0].size()-1;j>=0;j--){
            if(i+1<grid.size() && grid[i+1][j]!=1)
           dp[i][j]+= dp[i+1][j];
if(j+1<grid[0].size() && grid[i][j+1]!=1)
            dp[i][j]+=dp[i][j+1];
        }
    }
   
    return dp[0][0];

}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>>dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        if(obstacleGrid[0][0]==1)return 0;
        return fun2(0,0, obstacleGrid,dp);
    }
};