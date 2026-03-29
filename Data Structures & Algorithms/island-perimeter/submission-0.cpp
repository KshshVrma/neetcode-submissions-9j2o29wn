class Solution {
public:
int fun(vector<vector<int>>&grid, int i, int j){
    int delr[4]={0, -1, 0, 1};
    int delc[4]={-1, 0, 1, 0};
    int count=4;
    for(int it=0;it<4;it++){
        int nr=i+delr[it];
        int nc=j+delc[it];
        if(nr<0 || nr>=grid.size() || nc<0 || nc>=grid[0].size()){
            continue;
        }
        
            if(grid[nr][nc]==1){
         
                count--;
            }
        
    }

    return count;
}
    int islandPerimeter(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)
                count+=fun(grid, i, j);
            }
        }
        return count;
    }
};