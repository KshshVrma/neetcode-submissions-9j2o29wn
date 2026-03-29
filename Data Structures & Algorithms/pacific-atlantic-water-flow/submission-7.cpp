class Solution {
public:
bool bfs(vector<vector<int>>&heights, int i, int j){
    queue<pair<int,int>>q;
    bool pacific=false;
    bool atlantic=false;
    if(i==0||j==0){
        pacific=true;
    }
    if(i==heights.size()-1 || j==heights[0].size()-1){
        atlantic=true;
    }
    vector<vector<int>>vis(heights.size(),vector<int>(heights[0].size(), 0));
    q.push({i,j});
    vis[i][j]=1;
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
&&vis[row][col]!=1){
if(heights[r][c]>=heights[row][col]){
    if(row==0||col==0){pacific=true;}
    if(row==heights.size()-1 || col== heights[0].size()-1){
        atlantic=true;
    }
    vis[row][col]=1;
    q.push({row,col});
}



}

        }

    }
    return pacific && atlantic;
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>ans;

        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                if(bfs(heights, i, j)){
                    vector<int>temp={i,j};
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};
