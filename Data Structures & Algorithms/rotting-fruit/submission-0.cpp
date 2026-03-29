class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    grid[i][j]=9;
                }
            }
        }
        int maxi=0;
        while(!q.empty()){
            int one=q.front().first.first;
            int two=q.front().first.second;
            int three=q.front().second;
            q.pop();
            int delr[]={0,-1,0,1};
            int delc[]={-1,0,1,0};
            for(int i=0;i<4;i++){
                int row=one+delr[i];
                int col=two+delc[i];
                if(row>=0 && row<grid.size() && col<grid[0].size() && col>=0 && grid[row][col]==1){
                    q.push({{row,col},three+1});
                    maxi=max(maxi, three+1);
                    grid[row][col]=9;
                }

            }

          
        }
          for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return maxi;

    }
};
