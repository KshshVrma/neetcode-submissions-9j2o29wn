class Solution {
public:
void bfs(vector<vector<char>>&grid, int i, int j){
    queue<pair<int,int>>q;
    q.push({i,j});
    grid[i][j]='2';

    int delr[4]={0,-1,0,1};
    int delc[4]={-1,0,1,0};
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int row=r+delr[i];
            int col=c+delc[i];
            if(row>=0 && row<grid.size() 
            && col>=0 && col< grid[0].size()){
                if(grid[row][col]=='1'){
                    q.push({row,col});
                    grid[row][col]='2';
                }
            }
        }
    }
}

void dfs(vector<vector<char>>&grid, int it, int j){
    int delr[4]={0,-1,0,1};
    int delc[4]={-1,0,1,0};
    grid[it][j]='2';
    for(int i=0;i<4;i++){
        int nr=delr[i]+it;
        int nc=delc[i]+j;
        if(nr>=0 && nr<grid.size() && nc >=0 && nc <grid[0].size()){
 if(grid[nr][nc]=='1'){
    dfs(grid, nr,nc);
        }
    }
}
return ;
}
    int numIslands(vector<vector<char>>& grid) {
      int count=0;
      for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]=='1'){
            dfs(grid, i,j);
            count++;}
        }
      }
      return count;
    }
};
