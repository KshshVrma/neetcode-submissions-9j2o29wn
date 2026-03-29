class Solution {
public:
int bfs(vector<vector<int>>&grid, int i, int j){
    queue<pair<int,int>>q;
    q.push({i,j});
    grid[i][j]=2;
    int count=0;
    while(!q.empty()){
        int one=q.front().first;
        int two=q.front().second;
        q.pop();
        count++;

        int delr[4]={0,-1,0,1};
        int delc[4]={-1,0,1,0};

        for(int i=0;i<4;i++){
            int row=one+delr[i];
            int col=two+delc[i];
            if(row>=0 && row<grid.size() && col>=0  && col<grid[0].size() && grid[row][col]==1){
                q.push({row,col});
                grid[row][col]=2;
            }
        }
    }
    return count;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    ans=max(ans,bfs(grid,i,j));
                }

            }
        }
        return ans;
    }
};
