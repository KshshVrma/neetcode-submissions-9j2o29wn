class Solution {
public:
void bfs(vector<vector<char>>& board,vector<vector<int>>& vis,int i, int j){
queue<pair<int,int>>q;
int delr[4]={0,-1,0,1};
int delc[4]={-1,0,1,0};
q.push({i,j});
vis[i][j]=1;
while(!q.empty()){
    int r=q.front().first;
    int c=q.front().second;
  
    q.pop();
    for(int i=0;i<4;i++){
        int row=r+delr[i];
        int col=c+delc[i];
if(row>=0 && row<board.size() && col>=0 && col<board[0].size() 
&& board[row][col]=='O' && !vis[row][col]){
q.push({row,col});
vis[row][col]=1;
}


    }
}

}
    void solve(vector<vector<char>>& board) {
        vector<vector<int>>vis(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if((i==0||j==0||i==board.size()-1||j==board[0].size()-1) &&
                board[i][j]=='O' && !vis[i][j]){
                    bfs(board,vis, i,j);
                }
            }
        }
    


    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]=='O' && !vis[i][j]){
                board[i][j]='X';
            }
        }
    }}
};
