class Solution {
public:
void bfs(vector<vector<int>>&grid, int it, int jt){
queue<pair<int,int>>q;
q.push({it,jt});
int count=0;
int delr[4]={0,-1,0,1};
int delc[4]={-1,0,1,0};
vector<vector<int>>vis(grid.size(), vector<int>(grid[0].size(),-1));
vis[it][jt]=1;
while(!q.empty()){
    count++;
   
    int co=q.size();
    //  cout<<count<<":count and q size:"<<co<<endl;
    for(int i=0;i<co;i++){
 int r=q.front().first;
    int c=q.front().second;
    // cout<<r<<" "<<c<<endl;
    q.pop();
    for(int i=0;i<4;i++){
        int row=r+delr[i];
        int col=c+delc[i];
        if(row>=0 && row<grid.size() && col<grid[0].size() &&
        col>=0){
            // cout<<"{{inside the 4}}"<<row<<" and "<<col<<" \\ ";
            if(grid[row][col]==-1)continue;
            if(grid[row][col]==0){
                grid[it][jt]=count;
                return ;
            }else{
                if(vis[row][col]==-1){
 q.push({row,col});
 vis[row][col]=1;
                }
               
            }
        }
    }

    }
   


}


}
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]>0){
                 cout<<"yes actually a fresh call "<<i<<" - "<<j<<endl;
 bfs(grid, i,j);

            }
           
        }
    }
    }
};
