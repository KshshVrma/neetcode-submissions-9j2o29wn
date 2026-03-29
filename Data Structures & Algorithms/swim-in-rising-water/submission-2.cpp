class Solution {
public:
int delr[4]={0, -1, 0, 1};
int delc[4]={-1, 0, 1, 0};
bool fun(int mid, vector<vector<int>>&grid, vector<vector<int>>vis, int i,int j){

if(i<0 || j<0 || i>=grid.size() || j>=grid.size() || vis[i][j]!=-1 || grid[i][j]>mid)return false;

if(i==grid.size()-1 && j==grid.size()-1)return true;
vis[i][j]=1;

for(int it=0;it<4;it++){
if(fun(mid, grid, vis, i+delr[it], j+delc[it]))return true;
}

return false;

}
    int swimInWater(vector<vector<int>>& grid) {
        
    int l=grid[0][0];
    int r=grid.size()*grid.size()-1;
    vector<vector<int>>vis(grid.size(), vector<int>(grid.size(), -1));
    int ans=INT_MAX;
 
    while(l<=r){
        int mid=(l+r)/2;
      
        if(fun(mid, grid, vis, 0,0)){
    
            if(mid<ans)ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }

    return ans;
    }
};
