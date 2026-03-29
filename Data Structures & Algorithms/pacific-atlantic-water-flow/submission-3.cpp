class Solution {
public:
void bfs(vector<vector<int>>&heights, int i, int j,vector<vector<bool>>&vis){
    queue<pair<int,int>>q;
    
    q.push({i,j});
    vis[i][j]=true;
    int delr[4]={0,-1,0,1};
    int delc[4]={-1,0,1,0};

    while(!q.empty()){

        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
int row=r+delr[i];
int col=c+delc[i];

if(row>=0 && row<heights.size() && col>=0 && col<heights[0].size()
&&vis[row][col]!=true){
if(heights[r][c]<=heights[row][col]){
  
    vis[row][col]=true;
    q.push({row,col});
}



}

        }

    }
   
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>ans;
vector<vector<bool>>vis1(heights.size(),vector<bool>(heights[0].size(), false));
vector<vector<bool>>vis2(heights.size(),vector<bool>(heights[0].size(), false));

        for(int i=0;i<heights.size();i++){
            
            bfs(heights, i,0,vis1);
            
            bfs(heights,i,heights[0].size()-1,vis2);
        }
for(int j=0;j<heights[0].size();j++){
    bfs(heights, 0,j,vis1);
            bfs(heights,heights.size()-1,j,vis2);
               
            }


        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                if(vis1[i][j] && vis2[i][j]){
                    vector<int>temp={i,j};
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};
