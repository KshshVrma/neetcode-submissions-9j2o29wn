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
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
 bfs(grid, i, j);
 count++;
                }
               
            }

        }
        return count;
    }
};
